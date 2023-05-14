#ifndef _collision_h
#define _collision_h

#include "vector.h"
#include "rigidbody.h"

/// <summary>
/// ��ö����һ�ߵľ���
/// </summary>
void PointSegmentDistance(
	Vector p, Vector a, Vector b, 
	double* distanceSquared, Vector* contact);

/// <summary>
/// ����������ײ�����ײ
/// </summary>
bool IntersectAABBs(AABB a, AABB b);

void FindContactPoints(Rigidbody* bodyA, Rigidbody* bodyB, 
	Vector* contact1,Vector* contact2, int* contactCount);

void FindPolygonsContactPoints(
	Vector* verticesA, int numA,
	Vector* verticesB, int numB,
	Vector* contact1, Vector* contact2, int* contactCount);

void FindCirclePolygonContactPoint(
	Vector circleCenter, double radius,
	Vector* vertices, int num, Vector* cp);

/// <summary>
/// �������Բ�θ���ĽӴ���
/// </summary>
void FindCirclesContactPoint(
	Vector centerA, double radiusA, 
	Vector centerB, Vector* cp);

/// <summary>
/// ��ײ���
/// </summary>
bool Collide(
	Rigidbody* bodyA, Rigidbody* bodyB, 
	Vector* normal, double* depth);

bool IntersectCirclePolygons(
	Vector circleCenter, double circleRadius,
	Vector polygonCenter, Vector* vertices, int num,
	Vector* normal, double* depth);

/// <summary>
/// �ҵ���Բ������Ķ���
/// </summary>
int FindClosestPointPolygon(Vector circleCenter, Vector* vertices, int num);
/// <summary>
/// ��ȡԲ�ڶ�Ӧ���ϵ�ͶӰ
/// </summary>
void ProjectCircles(
	Vector center, double radius, 
	Vector axis, double* min, double* max);

bool IntersectPolygons(
	Vector centerA, Vector* verticesA, int numA,
	Vector centerB, Vector* verticesB, int numB,
	Vector* normal, double* depth);

/// <summary>
/// ��ȡ����ζ����ڶ�Ӧ���ϵ������СͶӰ������ĵ�ˣ�
/// </summary>
void ProjectVertices(
	Vector* vertices, int num, 
	Vector axis, double* min, double* max);

bool IntersectCircles(
	Vector centerA, double radiusA,
	Vector centerB, double radiusB,
	Vector* normal, double* depth);

#endif
