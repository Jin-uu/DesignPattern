# DesignPattern (MVC MVP ~~MVVM~~) EX projects

## How to run
1. Move to target dir
    ```bash
    cd ${project_dir}
    ```
    ex)
    ```bash
    cd ./MVP
    ```
   <br/><br/>
2. Configure Project
    ```bash
    cmake -B ${build_dir} -DCMAKE_BUILD_TYPE=${build_type}
    ```
    ex)
    ```bash
    cmake -B build -DCMAKE_BUILD_TYPE=Release
    ```
   <br/><br/>
3. Build Project
    ```bash
    cmake --build ${build_dir} --config ${build_type}
    ```
    ex)
    ```bash
    cmake --build build --config Release
    ```
   <br/><br/>
4. Execute Project
    ```bash
    ./build/${project_name}
    ```
    ex)
    ```bash
    ex) ./build/mvc_project
    ```