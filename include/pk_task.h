#ifndef TASK_H
#define TASK_H

#include <coroutine>
#include <concepts>
#include <exception>
#include "pk_common.h"
#include "bn_log.h"
#include "bn_format.h"


#define MAX_CONCURRENT_TASKS 32
#define MAX_ALLOCATED_TASKS 255

namespace pk {
    class Task {
        public:
        bool (*task)(int);
        unsigned char id = 0xFF;
        Task(bool (*t)(int));

        bool operator==(Task other);

        ~Task();
    };
}


#endif