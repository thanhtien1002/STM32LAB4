#include "scheduler.h"

void SCH_Init() {
    uint8_t i;
    for (i = 0; i < SCH_MAX_TASKS; i++) {
        SCH_Delete_Task(i);
    }
}


void SCH_Add_Task(void (*pFunction) (), uint32_t DELAY, uint32_t PERIOD) {
    DELAY = DELAY / TICK;
    PERIOD = PERIOD / TICK;

    uint8_t index;
    for (index = 0; index < SCH_MAX_TASKS; index++) {
        if (SCH_tasks_G[index].pTask == 0) break;  // Find an empty element
    }

    // If there is no space left in the array
    if (index == SCH_MAX_TASKS) return;

    // Add a task to a found location
    SCH_tasks_G[index].pTask = pFunction;
    SCH_tasks_G[index].Delay = DELAY;
    SCH_tasks_G[index].Period = PERIOD;
    SCH_tasks_G[index].Runme = 0;
}


void SCH_Update_ListTask(uint8_t index) {
    for (uint8_t i = index; i < SCH_MAX_TASKS - 1; i++) {
        SCH_tasks_G[i] = SCH_tasks_G[i + 1];
    }
    SCH_Delete_Task(SCH_MAX_TASKS - 1);
}


void SCH_Dispatch_Tasks() {
    for (uint8_t index = 0; index < SCH_MAX_TASKS; index++) {
        if (SCH_tasks_G[index].Runme) {
            (*SCH_tasks_G[index].pTask)();
            SCH_tasks_G[index].Runme--;

            // Processing and updating tasks
            sTask temp = SCH_tasks_G[index];
            SCH_Update_ListTask(index);  // Update the list after deleting a task
            if (temp.Period) {
                SCH_Add_Task(temp.pTask, temp.Period * TICK, temp.Period * TICK);
            }
        }
    }
}


void SCH_Update() {
    for (uint8_t index = 0; index < SCH_MAX_TASKS; index++) {
        if (SCH_tasks_G[index].pTask != 0) {
            if (SCH_tasks_G[index].Delay == 0) {
                SCH_tasks_G[index].Runme = 1;
                SCH_tasks_G[index].Delay = SCH_tasks_G[index].Period;
            } else {
                SCH_tasks_G[index].Delay--;
            }
        }
    }
}

void SCH_Delete_Task(const uint8_t TASK_INDEX) {
    SCH_tasks_G[TASK_INDEX].pTask = 0;
    SCH_tasks_G[TASK_INDEX].Delay = 0;
    SCH_tasks_G[TASK_INDEX].Period = 0;
    SCH_tasks_G[TASK_INDEX].Runme = 0;
}
