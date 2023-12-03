import subprocess
import sys
import os

# 用于检测其他需要的环境,cmake等等
def check_env_with_install(dependency):
  try:
    result = subprocess.run(["which", dependency], check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    print(f"{dependency} is installed, install dir: {result.stdout}")
    result = subprocess.run([dependency, "--version"], check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    print(f"{dependency} version: {result.stdout}")
  except subprocess.CalledProcessError:
    print(f"\033[31m{dependency} is not install, installing {dependency}...\033[0m")
    install_command = f"sudo apt-get install {dependency}"
    subprocess.run(install_command, shell=True, check=True)

# 执行 cmake，make构建项目
def build_project():
  current_path = os.path.abspath(os.path.dirname(__file__))
  root_path = current_path[:current_path.find("Miniob") + len("Miniob")]
  print(f"root path: {root_path}")
  build_path = root_path + "/build"
  print(f"build path: {build_path}")
  cmake_path = root_path + "/CMakeLists.txt"
  print(f"cmake path: {cmake_path}")
  try:
    build_cmd_1 = f"cd {root_path}"
    subprocess.run(build_cmd_1, shell=True, check=True)
    build_cmd_2 = f"mkdir {build_path}"
    if not os.path.exists(build_path):
      subprocess.run(build_cmd_2, shell=True, check=True)
    build_cmd_3 = f"cd {build_path}"
    subprocess.run(build_cmd_3, shell=True, check=True)
    build_cmd_4 = f"cmake {cmake_path} -B {build_path}" # -B 参数用于指定输出目录
    subprocess.run(build_cmd_4, shell=True, check=True)
    build_cmd_5 = f"make -C {build_path}"               # -C 参数用于指定Makefile所在的目录
    subprocess.run(build_cmd_5, shell=True, check=True)
  except subprocess.CalledProcessError:
    print("\033[31mFailed to build project\033[0m")

if __name__ == "__main__":
  check_env_with_install("git")
  check_env_with_install("cmake")
  check_env_with_install("gcc")
  check_env_with_install("g++")
  check_env_with_install("curl")

  build_project()