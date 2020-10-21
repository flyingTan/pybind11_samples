<font face="Times" >

[1.Introduction](#1)

[2.Pyblind11 C++ 混合编程](#2)

[3.Pyblind11 Pytorch C++/CUDA 混合编程](#3)


---


### <h3 id="1">Introduction</h3>

**BACKGROUND**：由于 Python 运行效率不如 C++，所以我们希望通过 C++ 生成高效运算库(.so, .lib)；通过结构适配让 Python 能够调用 C++库，从而提升运行效率。

##### [1]. GIT-REPO: 


### <h3 id="2">1. 原始方式。</h3>

[1] 参考博客 [Python 调用 C++:原生态、Boost Python 两种方式调用](https://www.jb51.net/article/104159.htm)，此方法相对繁琐，开发效率相对低效，不做进一步调研，有兴趣可以了解下。

### <h3 id="2"> 2. Pyblind11 C++ 混合编程。</h3>

[1]. **REQUIRES**: [Pyblind11官方 tutorial](https://pybind11.readthedocs.io/en/stable/basics.html)、[Github 源码](https://github.com/pybind/pybind11)

[2]. [**SAMPLE1**](sample1_add_op): Pybind Tutorial Sample。 

[3]. [**SAMPLE2**](sample2_add_op): 分离 include、src、sample、python-lib 文件，从而可以用Vscode Debug D C++ 和 Python 代码，提升效率。 


### <h3 id ="3">3. Pyblind11 Pytorch C++/CUDA 混合编程。</h3>

[1] **REQUIRE**: [libtorch(GPU Version)](https://pytorch.org/)、[CUDA](http://docs.nvidia.com/cuda/cuda-installation-guide-linux/index.html)、[Pybind11(build from source)](https://stackoverflow.com/questions/54704599/how-to-apt-install-python-pybind11)。

[2] [**SAMPLE3**](./sample3_torch_op): 写了一版简单 GPU(CPU) NMS，其中用到 libtorch、pybind，同时支持 Debug。 





