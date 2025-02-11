﻿#include "QRScanner.h"

#define DETECT_PROTOTXT_PATH "./ScanModel/detect.prototxt"
#define DETECT_CAFFE_MODEL_PATH "./ScanModel/detect.caffemodel"
#define SR_PROTOTXT_PATH "./ScanModel/sr.prototxt"
#define SR_CAFFE_MODEL_PATH "./ScanModel/sr.caffemodel"

QRScanner::QRScanner()
{
	detector = cv::makePtr<cv::wechat_qrcode::WeChatQRCode>(DETECT_PROTOTXT_PATH, DETECT_CAFFE_MODEL_PATH,
		SR_PROTOTXT_PATH, SR_CAFFE_MODEL_PATH);
}

void QRScanner::decodeSingle(const cv::Mat& img, std::string& qrCode)
{
	strDecoded = detector->detectAndDecode(img);
	if (strDecoded.size() > 0)
	{
		qrCode = strDecoded[0];
	}
#ifdef _DEBUG
	std::cout << "decode:" << qrCode << std::endl;
#endif // DEBUG
}

void QRScanner::decodeMultiple(const cv::Mat& img, std::string& qrCode)
{
	strDecoded = detector->detectAndDecode(img);
	for (int i = 0; i < strDecoded.size(); i++)
	{
		qrCode = strDecoded[i];
#ifdef _DEBUG
		std::cout << "decode:" << qrCode << std::endl;
#endif // DEBUG
	}
}