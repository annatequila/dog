# 完全和你项目一致的导入语法
from mars.input.test_plan_manager import TestPlanManager, get_default_manager

if __name__ == "__main__":
    # 1. 实例化导入的类
    plan1 = TestPlanManager("自动化性能测试")
    plan1.add_task("启动服务")
    plan1.add_task("压力压测")
    plan1.show_all_tasks()

    print("-" * 40)

    # 2. 使用模块导出的函数
    default_plan = get_default_manager()
    default_plan.add_task("基础连通性检测")
    default_plan.show_all_tasks()

