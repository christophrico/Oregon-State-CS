kernel
void
ArrayMultReduce( global const float *dA, global const float *dB, local float *prods, global float *dC )
{
	int gid = get_global_id( 0 );
	int numItems = get_local_size(0);
	int tnum = get_local_id(0);
	int workNum = get_group_id(0);

	prods[tnum] = dA[gid]*dB[gid];

	for(int i = 1; i < numItems; i *= 2)
	{
		int mask = 2*i - 1;
		barrier(CLK_LOCAL_MEM_FENCE);
		if((tnum & mask) == 0)
			prods[tnum] += prods[tnum+i];
	}

	barrier(CLK_LOCAL_MEM_FENCE);
	if(tnum == 0)
		dC[workNum] = prods[0];
}
