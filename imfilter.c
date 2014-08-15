
#define PIXEL_TYPE float
#define FILTER_TYPE float

#define FILTER_3X3(p1, p2, p3, filter) ( (p1)[0]*(filter)[0] + (p1)[1]*(filter)[1] + (p1)[2]*(filter)[2] + \
                                         (p2)[0]*(filter)[3] + (p2)[1]*(filter)[4] + (p2)[2]*(filter)[5] + \
                                         (p3)[0]*(filter)[6] + (p3)[1]*(filter)[7] + (p3)[2]*(filter)[8] )

void imfilter(PIXEL_TYPE *src, int w, int h, char *filter, FILTER_TYPE *dst)
{
    int i, j, stride;
    PIXEL_TYPE *psrc;
    FILTER_TYPE *pdst;

    stride = w;
    for (j = 0; j < h-2; j++)
    {
        psrc = src + (j+1)*stride + 1;
        pdst = dst + (j+1)*stride + 1;
        for (i = 0; i < w-2; i++)
        {
            *(pdst + i) = FILTER_3X3(psrc+i-1-stride, psrc+i-1, psrc+i-1+stride, filter);
        }
    }
}
