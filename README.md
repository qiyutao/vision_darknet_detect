# Vision Darknet Detect

Autoware package based on Darknet that supports Yolov3 and Yolov2 image detector.

### Requirements

* NVIDIA GPU with CUDA installed also no GPU using CPU

* The weights file must be placed in `vision_darknet_detect/darknet/data/`.

### How to launch

* From a sourced terminal:

    - `roslaunch vision_darknet_detect vision_yolo3_detect.launch`
    - `roslaunch vision_darknet_detect vision_yolo2_detect.launch`

* From Runtime Manager:

Computing Tab -> Detection/ vision_detector -> `vision_darknet_detect`
You can change the config and weights file, as well as other parameters, by clicking [app]

### Parameters

Launch file available parameters:

|Parameter| Type| Description|
----------|-----|--------
|`score_threshold`|*Double* |Detections with a confidence value larger than this value will be displayed. Default `0.5`.|
|`nms_threshold`|*Double*|Non-Maximum suppresion area threshold ratio to merge proposals. Default `0.45`.|
|`network_definition_file`|*String*|Network architecture definition configuration file. Default `yolov3.cfg`.|
|`pretrained_model_file`|*String*|Path to pretrained model. Default `yolov3.weights`.|
|`camera_id`|*String*|Camera workspace. Default `/`.|
|`image_src`|*String*|Image source topic. Default `/image_raw`.|

### Subscribed topics

|Topic|Type|Objective|
------|----|---------
|`/image_raw`|`sensor_msgs/Image`|Source image stream to perform detection.|
|`/config/Yolo3`|`autoware_msgs/ConfigSsd`|Configuration adjustment for threshold.|

### Published topics

|Topic|Type|Objective|
------|----|---------
|`/detection/vision_objects`|`autoware_msgs::DetectedObjectArray`|Contains the coordinates of the bounding box in image coordinates for detected objects.|

