# Caffe

[![Build Status](https://travis-ci.org/BVLC/caffe.svg?branch=master)](https://travis-ci.org/BVLC/caffe)
[![License](https://img.shields.io/badge/license-BSD-blue.svg)](LICENSE)

Caffe is a deep learning framework made with expression, speed, and modularity in mind.
It is developed by the Berkeley Vision and Learning Center ([BVLC](http://bvlc.eecs.berkeley.edu)) and community contributors.

Check out the [project site](http://caffe.berkeleyvision.org) for all the details like

- [DIY Deep Learning for Vision with Caffe](https://docs.google.com/presentation/d/1UeKXVgRvvxg9OUdh_UiC5G71UMscNPlvArsWER41PsU/edit#slide=id.p)
- [Tutorial Documentation](http://caffe.berkeleyvision.org/tutorial/)
- [BVLC reference models](http://caffe.berkeleyvision.org/model_zoo.html) and the [community model zoo](https://github.com/BVLC/caffe/wiki/Model-Zoo)
- [Installation instructions](http://caffe.berkeleyvision.org/installation.html)

and step-by-step examples.

[![Join the chat at https://gitter.im/BVLC/caffe](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/BVLC/caffe?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

Please join the [caffe-users group](https://groups.google.com/forum/#!forum/caffe-users) or [gitter chat](https://gitter.im/BVLC/caffe) to ask questions and talk about methods and models.
Framework development discussions and thorough bug reports are collected on [Issues](https://github.com/BVLC/caffe/issues).

Happy brewing!

## License and Citation

Caffe is released under the [BSD 2-Clause license](https://github.com/BVLC/caffe/blob/master/LICENSE).
The BVLC reference models are released for unrestricted use.

Please cite Caffe in your publications if it helps your research:

    @article{jia2014caffe,
      Author = {Jia, Yangqing and Shelhamer, Evan and Donahue, Jeff and Karayev, Sergey and Long, Jonathan and Girshick, Ross and Guadarrama, Sergio and Darrell, Trevor},
      Journal = {arXiv preprint arXiv:1408.5093},
      Title = {Caffe: Convolutional Architecture for Fast Feature Embedding},
      Year = {2014}
    }



## Arie's Note (Testing robustness against adversarial images)
1. Prepare pretrained weights (.caffemodel) and training-validation setting (train_val.prototxt), put them into respective folder under directory "models", for example:

models > squeezenet

2. Prepare LMDB file of generated adversarial images.
Modify and run file in examples > imagenet > create_imagenet.sh
Run it in root directory of caffe:

./examples/imagenet/create_imagenet.sh

3. Modify "train_cal.prototxt" file of the respective model to update the location of training and validation LMDB files.
To evaluate the accuracy performance of a model, run using test option, for example (using GPU):


ALEXNET

./build/tools/caffe test --model=models/bvlc_alexnet/train_val.prototxt --weights=models/bvlc_alexnet/bvlc_alexnet.caffemodel --gpu all


DEEPCOMPRESSION

./build/tools/caffe test --model=models/deepcompression/train_val.prototxt --weights=models/deepcompression/deepcompression.caffemodel --gpu all


INQ

./build/tools/caffe test --model=models/inq/train_val.prototxt --weights=models/inq/inq.caffemodel --gpu all


PROPOSED

./build/tools/caffe test --model=models/proposed/train_val.prototxt --weights=models/proposed/proposed.caffemodel --gpu all

SQUEEZENET
./build/tools/caffe test --model=models/squeezenet/train_val.prototxt --weights=models/squeezenet/squeezenet.caffemodel --gpu all
