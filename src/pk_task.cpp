#include "pk_task.h"

namespace {
    unsigned char taskIDs[MAX_ALLOCATED_TASKS] = { 0 };
    unsigned char numTasks = 0;
};

pk::Task::Task(bool (*t)(int)) {
    BN_ASSERT(numTasks < MAX_ALLOCATED_TASKS, "Too many tasks created");
    for (unsigned char i = 0; i < MAX_ALLOCATED_TASKS; i++) {
        if (!taskIDs[i]) {
            taskIDs[i] = MAX_ALLOCATED_TASKS - i;
            id = taskIDs[i];
            numTasks++;
            bn::log(bn::format<64>("Task {} created. {} task(s) allocated", id, numTasks));
            task = t;
            break;
        }
    }
}

bool pk::Task::operator==(Task other) { return id == other.id; }

pk::Task::~Task() { taskIDs[id] = 0xFF;numTasks--; }