kernel
void
AutoCorrelate( global const float *dArray, global float *dSums)
{
  int size = get_global_size(0);
  int gid = get_global_id(0);
  int shift = gid;

  float sum = 0.0;

  for(int i = 0; i < size; i++)
  {
    sum += dArray[i] * dArray[i + shift];
  }

  dSums[shift] = sum;
}
