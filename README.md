# Zen - The Video Upscaler
## Overview
---
**Video upscaling is a very complex task, and currently there are many ways of doing it. This software definitely does not use any AI upscaling techniques like super-sampling, rather, it just relies on the mathematical resampling known as the Sinc(Lanczos) resampling.**
## Project Specification
---
The project implements an algorithmic upscaler that uses **Sinc(Lanczos)** resampling in order to interpolate and upscale an image. This technology is then going to be converted to a single stage in multi-stage data processing pipeline. 

The first stage in this upscaling pipeline is going to be a conversion stage, to convert the video format provided, i.e. .mov, .mp4, .avi, into a standardised video format. This will be implemented for the express purpose of reducing supportive complexity, as the higher the number of video formats supported, the larger the larger the decomposition stage may need be. This can be slightly problematic as it presents the challenge of decomposing multiple different formats, some of which may be be impossible to uncouple in practicality due to their post-compilation structure. The ideal data format in this case can be one that primarily decouples the pictoral and audial data.

The second stage in the pipeline is a decomposition stage for the separation of pictoral and audial components of the standardised video format.

The third stage would be individual upscaling, where each picture frame is upscaled individually. Here, the algorithmic use of Sinc(Lanczos) resampling is expected to be implemented.Here, certain multi-threaded optimisations may also be applied such as a scheduler that provides an initial frame queue and a final frame queue. Each frame is assorted a frame sequence number, and this sequence number should be used at the final frame queue to reorder aimges back into their correct order. Meanwhile, actual upscaling can be performed by one thread assigned to one frame at a time, as this allows for a more acyclical approach to the optimisation problem.

The penultimate stage, the fourth stage, would be the video recomposition stage, where the now upscaled pictoral components and the audial components can be recombined into one dataset.

The final stage would the video recompilation stage. Here, the video can be recompiled into the original file format that it was received as. Here, technologies that have already been initialised (if available) may be used or an in-house solution may be applied.
## References
---
* [Sinc(Lanzos) filtering](https://en.wikipedia.org/wiki/Lanczos_resampling) - A wikipedia article on this method.