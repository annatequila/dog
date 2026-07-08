# 模拟编译后的扩展模块对外提供 TestPlanManager 类
class TestPlanManager:
    def __init__(self, plan_name: str):
        self.plan_name = plan_name
        self.task_list = []

    def add_task(self, task_name: str):
        self.task_list.append(task_name)
        print(f"[{self.plan_name}] 添加任务：{task_name}")

    def show_all_tasks(self):
        print(f"测试计划 {self.plan_name} 所有任务：{self.task_list}")

# 扩展模块也可以导出全局函数
def get_default_manager():
    return TestPlanManager("默认测试计划")

