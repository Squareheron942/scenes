#ifndef PK_TASKMANAGER_H
#define PK_TASKMANAGER_H

#include <coroutine>
#include "pk_task.h"
#include "bn_vector.h"
#include "bn_forward_list.h"
#include "bn_assert.h"
#include "bn_log.h"
#include "bn_string.h"
#include "bn_format.h"

namespace pk {
    class TaskManager {
        private:
        static inline int iterations[MAX_CONCURRENT_TASKS] = { 0 };
        public:
        static inline bn::forward_list<Task, MAX_CONCURRENT_TASKS> tasks;
        static inline void update() {
            int index = 0;
            auto task = tasks.begin(), prev = tasks.before_begin();
            while (task != tasks.end()) {
                index++;
                iterations[index]++;
                if (task->task(iterations[index])) {
                    bn::log(bn::format<64>("Task {} finished, {} tasks remaining", index, tasks.size() - 1));
                    iterations[index] = 0;
                    task = tasks.erase_after(prev);
                } else {++task;++prev;}
            }
        }
        static inline void add(pk::Task h, bool force = false) {
            bool newval = true;
            if (!force) for (auto task : tasks) if (task == h) newval = false;
            if (newval) tasks.push_front(h);
            BN_ASSERT(tasks.size() <= MAX_CONCURRENT_TASKS, "Too many concurrent tasks");
        }
        private:
            TaskManager() {};
    };
};

#endif