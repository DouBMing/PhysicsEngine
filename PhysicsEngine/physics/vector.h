#ifndef _vector_h
#define _vector_h

#include "boolean.h"

#define PI 3.1415926
typedef struct transform Transform;

typedef struct vector
{
	double x;
	double y;
}Vector;

/// <summary>
/// ��������
/// </summary>
Vector GetVector(double x, double y);
/// <summary>
/// ������
/// </summary>
Vector GetZero();

/// <summary>
/// �����ӷ�
/// </summary>
Vector Add(Vector a, Vector b);
/// <summary>
/// ��������
/// </summary>
Vector Substract(Vector a, Vector b);
/// <summary>
/// ȡ��
/// </summary>
Vector Negate(Vector v);

/// <summary>
/// ����
/// </summary>
Vector ScalarProduct(Vector v, double c);
/// <summary>
/// ���
/// </summary>
double DotProduct(Vector a, Vector b);
/// <summary>
/// ���
/// </summary>
double CrossProduct(Vector a, Vector b);

/// <summary>
/// �ж��������Ƿ����
/// </summary>
bool IsVectorsEqual(Vector a, Vector b);

bool IsNearlyEqual(double a, double b);

bool IsVectorsNearlyEqual(Vector a, Vector b);

/// <summary>
/// ȡ��λ����
/// </summary>
Vector Normalize(Vector v);
/// <summary>
/// ȡģ
/// </summary>
double GetVectorLength(Vector v);

double GetLengthSquared(Vector v);
/// <summary>
/// �������
/// </summary>
double Distance(Vector a, Vector b);

double GetDistanceSquared(Vector a, Vector b);
/// <summary>
/// ����任
/// </summary>
Vector DoTransform(Vector v, Transform transform);

/// <summary>
/// ͨ�������ƶ�����
/// </summary>
void MovePenByVector(Vector position);
/// <summary>
/// ͨ����������
/// </summary>
void DrawLineByVector(Vector direction);

#endif
