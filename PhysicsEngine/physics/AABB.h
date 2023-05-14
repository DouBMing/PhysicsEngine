#ifndef _AABB_h
#define _AABB_h

#include "vector.h"

/// <summary>
/// �������ײ��
/// </summary>
typedef struct AABB
{
	Vector min;
	Vector max;
}AABB;

AABB GetAABB(double minX, double minY, double maxX, double maxY);

#endif
