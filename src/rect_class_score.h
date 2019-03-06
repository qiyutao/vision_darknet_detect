#ifndef RECTCLASSSCORE_H_
#define RECTCLASSSCORE_H_

#include <sstream>
#include <string>

namespace Yolo3
{
    enum YoloDetectorClasses//using traffic sign for default cfg and weights
    {
        STRAIGHT,LEFT,RIGHT,STOP,NOHONK,CROSSWALK,
    };
}

template<typename _Tp> class RectClassScore
{
public:
	_Tp x, y, w, h;
	_Tp score;
	unsigned int class_type;
	bool enabled;

	inline std::string toString()
	{
		std::ostringstream out;
		out << class_type << "(x:" << x << ", y:" << y << ", w:" << w << ", h:" << h << ") =" << score;
		return out.str();
	}
	inline std::string GetClassString()
	{
		switch (class_type)
		{
            case Yolo3::STRAIGHT: return "straight";
            case Yolo3::LEFT: return "left";
            case Yolo3::RIGHT: return "right";
            case Yolo3::STOP: return "stop";
            case Yolo3::NOHONK: return "nohonk";
            case Yolo3::CROSSWALK: return "crosswalk";
			default:return "error";
		}
	}
	inline int GetClassInt()
    {
        switch (class_type)
        {
            case Yolo3::STRAIGHT: return 0;
            case Yolo3::LEFT: return 1;
            case Yolo3::RIGHT: return 2;
            case Yolo3::STOP: return 3;
            case Yolo3::NOHONK: return 4;
            case Yolo3::CROSSWALK: return 5;
            
            default:return 0;
        }
	}
};

#endif /* RECTCLASSSCORE_H_ */
