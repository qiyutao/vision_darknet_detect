# 交通标志检测模块说明文档


### 功能

* 检测前方道路交通标志，获取交通标志位置及内容

### 模块启动方法

* 使用roslaunch运行traffic_sign_detect.launch文件:

    - `$ roslaunch traffic_sign_detect traffic_sign_detect.launch`

### 目录结构
```
├── CMakeLists.txt #编译配置文件
├── README.md
├── darknet
│   ├── cfg
│   │   └── yolov3.cfg
│   └── src
│       ├── activation_kernels.cu
│       ├── activation_layer.c
│       ├── activation_layer.h
│       ├── activations.c
│       ├── activations.h
│       ├── avgpool_layer.c
│       ├── avgpool_layer.h
│       ├── avgpool_layer_kernels.cu
│       ├── batchnorm_layer.c
│       ├── batchnorm_layer.h
│       ├── blas.c
│       ├── blas.h
│       ├── blas_kernels.cu
│       ├── box.c
│       ├── box.h
│       ├── classifier.h
│       ├── col2im.c
│       ├── col2im.h
│       ├── col2im_kernels.cu
│       ├── connected_layer.c
│       ├── connected_layer.h
│       ├── convolutional_kernels.cu
│       ├── convolutional_layer.c
│       ├── convolutional_layer.h
│       ├── cost_layer.c
│       ├── cost_layer.h
│       ├── crnn_layer.c
│       ├── crnn_layer.h
│       ├── crop_layer.c
│       ├── crop_layer.h
│       ├── crop_layer_kernels.cu
│       ├── cuda.c
│       ├── cuda.h
│       ├── darknet.h
│       ├── data.c
│       ├── data.h
│       ├── deconvolutional_kernels.cu
│       ├── deconvolutional_layer.c
│       ├── deconvolutional_layer.h
│       ├── demo.c
│       ├── demo.h
│       ├── detection_layer.c
│       ├── detection_layer.h
│       ├── dropout_layer.c
│       ├── dropout_layer.h
│       ├── dropout_layer_kernels.cu
│       ├── gemm.c
│       ├── gemm.h
│       ├── gru_layer.c
│       ├── gru_layer.h
│       ├── im2col.c
│       ├── im2col.h
│       ├── im2col_kernels.cu
│       ├── image.c
│       ├── image.h
│       ├── l2norm_layer.c
│       ├── l2norm_layer.h
│       ├── layer.c
│       ├── layer.h
│       ├── list.c
│       ├── list.h
│       ├── local_layer.c
│       ├── local_layer.h
│       ├── logistic_layer.c
│       ├── logistic_layer.h
│       ├── lstm_layer.c
│       ├── lstm_layer.h
│       ├── matrix.c
│       ├── matrix.h
│       ├── maxpool_layer.c
│       ├── maxpool_layer.h
│       ├── maxpool_layer_kernels.cu
│       ├── network.c
│       ├── network.h
│       ├── normalization_layer.c
│       ├── normalization_layer.h
│       ├── option_list.c
│       ├── option_list.h
│       ├── parser.c
│       ├── parser.h
│       ├── region_layer.c
│       ├── region_layer.h
│       ├── reorg_layer.c
│       ├── reorg_layer.h
│       ├── rnn_layer.c
│       ├── rnn_layer.h
│       ├── route_layer.c
│       ├── route_layer.h
│       ├── shortcut_layer.c
│       ├── shortcut_layer.h
│       ├── softmax_layer.c
│       ├── softmax_layer.h
│       ├── stb_image.h
│       ├── stb_image_write.h
│       ├── tree.c
│       ├── tree.h
│       ├── upsample_layer.c
│       ├── upsample_layer.h
│       ├── utils.c
│       ├── utils.h
│       ├── yolo_layer.c
│       └── yolo_layer.h
├── interface.yaml
├── launch
│   └── traffic_sign_detect.launch
├── package.xml
└── src
    ├── gencolors.cpp
    ├── rect_class_score.h
    ├── vision_darknet_detect.cpp
    ├── vision_darknet_detect.h
    └── vision_darknet_detect_node.cpp

```

### 模块输入

/image_raw(sensor_msgs/Image): 相机视频流输入

### 模块输出

/detection/vision_objects(rockauto_msg::/DetectedObjectArray): 消息列表，包含了检测到的交通标志在视频帧的位置坐标，交通标志内容标签和置信度

### 模块运行所依赖的节点

roslaunch相机节点，启动相机，输出/image_raw消息

### 模块内节点
```
1.traffic_sign_detect
    输入：/image_raw(sensor_msgs/Image)
        待检测视频帧
    输出：/detection/vision_objects(rockauto_msg::/DetectedObjectArray)
        检测到的交通标志相关信息
    功能：通过将视频流中的图片输入到yolo v3的网络中，使用深度学习的方法对图片中的交通标志进行检测，输出相关信息
    原理：YOLO将物体检测作为一个回归问题进行求解，输入图像经过一次inference（推理），便能得到图像中所有物体的位置和其所属类别及相应的置信概率。而rcnn/fast rcnn/faster rcnn将检测结果分为两部分求解：物体类别（分类问题），物体位置即bounding box（回归问题）。通过对yolo.cfg文件的编辑，建立相应的yolo v3网络，放入已训练完成的权重文件yolov3.weights进行检测
    
```
