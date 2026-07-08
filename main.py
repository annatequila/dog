import logging
import os
import sys
from logging.handlers import TimedRotatingFileHandler
import threading
from pathlib import Path
import tempfile
import datetime


# ############################  日志设置
_LOG = logging.getLogger(__name__) # 每个文件独立日志
_LOG_FOLDER = os.path.join(os.path.expanduser('~'), 'Desktop/cc/dog', 'launcher') # join（路径，路径，路径）拼接路径
_LOG_FILE = os.path.join(_LOG_FOLDER, 'mars_launcher.log') # 拼接具体路径  
# 日志格式
_FMT = '%(asctime)s - %(levelname)s - [%(filename)s:%(lineno)s] - %(message)s' 
"""
`%(asctime)s`打印日志生成的完整时间，默认格式类似：`2026-07-07 16:20:15,456`
`%(levelname)s`打印日志级别，默认格式类似：`INFO`、`DEBUG`、`WARNING`、`ERROR`、`CRITICAL`
`%(filename)s`打印日志所在的文件名，默认格式类似：`main.py`
`%(lineno)s`打印日志所在的行号，默认格式类似：`10`
`%(message)s`打印日志的内容，默认格式类似：`This is a log message.`
"""
_FORMATTER = logging.Formatter(_FMT) # 以前面定义好的日志格式字符串 `_FMT` 为规则，**创建一个日志格式化器对象**，
_STREAM_HANDLER = logging.StreamHandler(sys.stdout) # 把日志输出到一个数据流（流对象）。 stdout = standard output，标准输出流；
_STREAM_HANDLER.setFormatter(_FORMATTER) # **给当前输出处理器绑定日志格式化规则**。

_LOG.setLevel(logging.INFO) 
"""
给当前日志器 _LOG 设置日志过滤等级，只有等级 ≥ INFO 的日志才会被输出，低于 INFO 的直接丢弃。日志等级从小到大：
DEBUG  调试信息，最低 
INFO 正常运行信息 
WARNING 警告 
ERROR 错误 
CRITICAL  严重故障，最高 
"""
_LOG.addHandler(_STREAM_HANDLER) #  
"""
把控制台输出处理器 _STREAM_HANDLER 添加到日志器 _LOG。
Handler 定义日志输出去哪里，这里代表：日志输出到终端屏幕。
"""

# ############################  
# 创建日志文件夹
try:
    os.makedirs(_LOG_FOLDER)
    print(('Created log folder at path {}'.format(_LOG_FOLDER)), flush=True)
except OSError as e:
    if os.path.exists(_LOG_FOLDER):
        print('Log folder already exist.', flush=True)
    else:
        print('Failed to create log folder at path {}, reason: {}'.format(
            _LOG_FOLDER, e),flush=True,)
_FILE_HANDLER = TimedRotatingFileHandler(
    _LOG_FILE, when='midnight', backupCount=60
)# 创建一个按时间自动切割日志文件的处理器对象，每天凌晨 0 点自动切分日志 ，最多保存60份
_FILE_HANDLER.setFormatter(_FORMATTER) # 设置文件日志格式
_LOG.addHandler(_FILE_HANDLER) # 将文件日志处理器添加到日志器 同时输出文件日志和打印屏幕


# The exit event initiated by frontend (Chrome) termination.
_EXIT = threading.Event()
# The exit event initiated by signal (e.g. SIGINT).
_SIGNAL_EXIT = threading.Event()
_LOCK = threading.Lock()
_MARS_DIR = os.path.join(os.path.expanduser('~'), 'Mars')
_DEV_MARS_DIR = os.path.join(  Path(__file__).resolve().parents[1], 'misc', 'build') # 'misc', 'build'的绝对路径

_MARS_URL = 'http://127.0.0.1:12000'
_DEV_MARS_URL = 'http://127.0.0.1:4200'
_CHROME_URL = ''
_STATION_MANAGER_TIMEOUT = 20
_PLATFORM = ''
_STATION_MANAGER = ''
_CONTROLLER = ''
_STR_CODEC = ''

_TEMP_DIR = tempfile.gettempdir() # 读取系统全局临时目录
_MINIMUM_CHROME_VER = 81 # 定义最低兼容 Chrome 浏览器版本号。
_LINUX = 'linux'
_WINDOWS = 'windows'
_HOME = str(Path.home()) 
"""
获取当前用户家目录路径对象等价 `os.path.expanduser("~")`,全局缓存用户根目录，后续读取用户配置、日志目录、缓存目录时直接复用。
"""
env = os.environ

# Debug GRPC, this should be disabled for production.
_DEBUG_GRPC = False # 定义全局布尔开关，用来控制是否开启 gRPC 调试日志，默认关闭
_DEBUG_GRPC_LOG = os.path.join(
    os.path.expanduser('~'),
    'MarsLog',
    'station_manager',
    f'station_manager_debug_{datetime.now().strftime("%Y-%m-%d-%H-%M-%S")}.log',
)
if _DEBUG_GRPC:
  env['GODEBUG'] = 'http2debug=2'







# ############################
def add(a, b):
    c = a + b
    return c


# ############################
if __name__ == '__main__':
    _LOG.info('\n\n\t\t=====  Start Launcher on %s platform =====', _PLATFORM)





    res = add(5 ,3)
    print(res)

    

    