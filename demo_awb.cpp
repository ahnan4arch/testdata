#include "ks.h"
#include "Ksmedia.h"


CComPtr<IGraphBuilder> cpGraph;
CComPtr<ICaptureGraphBuilder2>cpCaptureGraphBuilter2;
CComPtr<IBaseFilter>cpVideoCapture;


//Read  property demo

Void ReadDemo()
{
    HRESULT hr;
    IAMVideoProcAmp *pVideoProc;
    /* [out] */ long Min;
    /* [out] */ long Max;
    /* [out] */ long SteppingDelta;
    /* [out] */ long Default;
    /* [out] */ long CapsFlags = 0;
    long val_brightness, flag;
    long val_whitebalance;
    long val_gain;

    hr = cpVideoCapture->QueryInterface(__uuidof(IAMVideoProcAmp), (void **)&pVideoProc);
    if( FAILED(hr)){ printf("Querying failed\n");}
    pVideoProc->GetRange( KSPROPERTY_VIDEOPROCAMP_BRIGHTNESS, &Min, &Max, &SteppingDelta, &Default, &CapsFlags);
    pVideoProc->Get( KSPROPERTY_VIDEOPROCAMP_BRIGHTNESS, &val_brightness, &flag);


    pVideoProc->Get( KSPROPERTY_VIDEOPROCAMP_WHITEBALANCE, &val_whitebalance, &flag);

   pVideoProc->Get( KSPROPERTY_VIDEOPROCAMP_GAIN, &val_gain, &flag);

    int g = 0;


    pVideoProc->Release();

}

