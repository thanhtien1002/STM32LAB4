#include "scheduler.h"

// Khởi tạo bộ lập lịch
void SCH_Init() {
    uint8_t i;
    for (i = 0; i < SCH_MAX_TASKS; i++) {
        SCH_Delete_Task(i);
    }
}

// Thêm tác vụ mới vào bộ lập lịch
void SCH_Add_Task(void (*pFunction) (), uint32_t DELAY, uint32_t PERIOD) {
    DELAY = DELAY / TICK;  // Đổi DELAY và PERIOD về đơn vị TICK
    PERIOD = PERIOD / TICK;

    uint8_t index;
    for (index = 0; index < SCH_MAX_TASKS; index++) {
        if (SCH_tasks_G[index].pTask == 0) break;  // Tìm phần tử trống
    }

    // Nếu không còn chỗ trống trong mảng
    if (index == SCH_MAX_TASKS) return;

    // Thêm tác vụ vào vị trí tìm được
    SCH_tasks_G[index].pTask = pFunction;
    SCH_tasks_G[index].Delay = DELAY;
    SCH_tasks_G[index].Period = PERIOD;
    SCH_tasks_G[index].Runme = 0;
}

// Cập nhật danh sách tác vụ sau khi một tác vụ được xử lý
void SCH_Update_ListTask(uint8_t index) {
    for (uint8_t i = index; i < SCH_MAX_TASKS - 1; i++) {
        SCH_tasks_G[i] = SCH_tasks_G[i + 1];
    }
    SCH_Delete_Task(SCH_MAX_TASKS - 1);  // Xóa phần tử cuối cùng
}

// Đảm bảo chỉ một tác vụ được thực thi tại một thời điểm
void SCH_Dispatch_Tasks() {
    for (uint8_t index = 0; index < SCH_MAX_TASKS; index++) {
        if (SCH_tasks_G[index].Runme) {
            (*SCH_tasks_G[index].pTask)();  // Gọi hàm của tác vụ
            SCH_tasks_G[index].Runme--;  // Giảm số lần chạy của tác vụ

            // Xử lý và cập nhật tác vụ
            sTask temp = SCH_tasks_G[index];
            SCH_Update_ListTask(index);  // Cập nhật danh sách sau khi xóa tác vụ
            if (temp.Period) {
                SCH_Add_Task(temp.pTask, temp.Period * TICK, temp.Period * TICK);
            }
        }
    }
}

// Cập nhật trạng thái của các tác vụ, kiểm tra thời gian delay
void SCH_Update() {
    for (uint8_t index = 0; index < SCH_MAX_TASKS; index++) {
        if (SCH_tasks_G[index].pTask != 0) {  // Kiểm tra xem có tác vụ hay không
            if (SCH_tasks_G[index].Delay == 0) {
                SCH_tasks_G[index].Runme = 1;
                SCH_tasks_G[index].Delay = SCH_tasks_G[index].Period;
            } else {
                SCH_tasks_G[index].Delay--;
            }
        }
    }
}

// Xóa một tác vụ khỏi bộ lập lịch
void SCH_Delete_Task(const uint8_t TASK_INDEX) {
    SCH_tasks_G[TASK_INDEX].pTask = 0;
    SCH_tasks_G[TASK_INDEX].Delay = 0;
    SCH_tasks_G[TASK_INDEX].Period = 0;
    SCH_tasks_G[TASK_INDEX].Runme = 0;
}
