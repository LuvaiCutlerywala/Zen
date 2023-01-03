# TODO list for this project

## Overarching goals
---
1. **Develop a functional image upscaler implementing Sinc(Lanczos) resampling.**
2. **Develop a video decomposition tool that can decompose standard video files into separate video and audio files.**
3. **Implement image upscaling to individual video frames.**
4. **Develop a video composition tool that can be used to recompile the video file.**
5. **Develop an exporter that allows the video file to be exported in multiple formats.**
6. **Develop a custom pipeline orchestrator that allows for easy orchestration of a pipeline.**

## TODO code stuff
---
 - [x] Fix the segmentation fault in the BMPHEADER deserialisation methods.
 - [ ] Rewrite the current processors with the Matrix class.
 - [ ] Complete the Convolver class.
 - [ ] Test the convolution methods with the Gaussian and Box blur.