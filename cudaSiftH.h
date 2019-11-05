#ifndef CUDASIFTH_H
#define CUDASIFTH_H

#include "cudautils.h"
#include "cudaImage.h"

//********************************************************//
// CUDA SIFT extractor by Marten Bjorkman aka Celebrandil //
//********************************************************//  
class TempMemory;
int ExtractSiftLoop(SiftData &siftData, const CudaImage &img, int numOctaves, double initBlur, float thresh, float lowestScale, float subsampling, TempMemory &memoryTmp);
void ExtractSiftOctave(SiftData &siftData, const CudaImage &img, int octave, float thresh, float lowestScale, float subsampling, TempMemory &memoryTmp);
double ScaleDown(const SiftData &siftData, const CudaImage &res, const CudaImage &src, float variance);
double ScaleUp(const SiftData &siftData, const CudaImage &res, const CudaImage &src);
double ComputeOrientations(cudaTextureObject_t texObj, const CudaImage &src, SiftData &siftData, int octave);
double ExtractSiftDescriptors(cudaTextureObject_t texObj, SiftData &siftData, float subsampling, int octave);
double OrientAndExtract(cudaTextureObject_t texObj, SiftData &siftData, float subsampling, int octave);
double RescalePositions(SiftData &siftData, float scale);
double LowPass(const SiftData &siftData, const CudaImage &res, const CudaImage &src, float scale);
void PrepareLaplaceKernels(int numOctaves, float initBlur, float *kernel);
double LaplaceMulti(const SiftData &siftData, cudaTextureObject_t texObj, const CudaImage &baseImage, const CudaImage *results, int octave);
double FindPointsMulti(const CudaImage *sources, SiftData &siftData, float thresh, float edgeLimit, float factor, float lowestScale, float subsampling, int octave);

#endif
