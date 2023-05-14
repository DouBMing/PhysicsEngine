#ifndef _rigidbody_h
#define _rigidbody_h

#include <string.h>
#include "AABB.h"

typedef char* string;

typedef enum shapeType
{
	CIRCLE = 0,
	BOX = 1,
	POLYGON = 2,
}ShapeType;

typedef struct rigidbody
{
	Vector position;
	Vector linearVelocity;
	double angle;
	double angularVelocity;
	Vector force;

	ShapeType shapeType;
	/// <summary>
	/// ���
	/// </summary>
	double area; 
	/// <summary>
	/// �ܶ� 
	/// </summary>
	double density;
	/// <summary>
	/// ����
	/// </summary>
	double mass;
	/// <summary>
	/// �����ĵ������������
	/// </summary>
	double invMass;
	/// <summary>
	/// ת������
	/// </summary>
	double inertia;
	/// <summary>
	/// ת�������ĵ���
	/// </summary>
	double invInertia;
	/// <summary>
	/// ����ϵ��
	/// </summary>
	double restitution;
	/// <summary>
	/// �Ƿ��Ǿ�̬
	/// </summary>
	bool isStatic;
	/// <summary>
	/// �Ƿ����˶�ѧ�ģ���������Ӱ�죩
	/// </summary>
	bool isKinematic;
	double radius;
	double width;
	double height;
	double staticFriction;
	double dynamicFriction;
	
	/// <summary>
	/// ������
	/// </summary>
	int vertexNumber;
	/// <summary>
	/// ���㣬ͨ��������
	/// </summary>
	Vector* vertices;
	/// <summary>
	/// ����任��Ķ���
	/// </summary>
	Vector* transformedVertices;
	AABB aabb;

	bool transformUpdateRequired;
	bool aabbUpdateRequired;
}Rigidbody;

/// <summary>
/// ��ʼ������
/// </summary>
Rigidbody* InitBody(
	ShapeType shapeType, double area, double density, double mass,
	double inertia, double restitution, bool isStatic, double radius,
	double width, double height, int vertexNumber, Vector* vertices);

/// <summary>
/// ��ʼ��Բ�θ���
/// </summary>
Rigidbody* CreateCircleBody(double radius, double density,
	bool isStatic, double restitution);

/// <summary>
/// ��ʼ�����θ���
/// </summary>
Rigidbody* CreateBoxBody(double width, double height, double density,
	bool isStatic, double restitution);
/// <summary>
/// �������ζ���
/// </summary>
Vector* CreateBoxVertices(double width, double height);

Rigidbody* CreatePolygonBody(Vector* vertices, int num, double density,
	bool isStatic, double restitution);
Vector CalculateCenterPoint(Vector* vertices, int num);
double CalculatePolygonArea(Vector* vertices, int num);
double CalculatePolygonInertia(Vector* vertices, int num, double mass);

/// <summary>
/// ��ñ任��Ķ���
/// </summary>
Vector* GetTransformedVertices(Rigidbody* body);
int* CreateBoxTriangles();

/*�����˶�*/
void MoveBody(Rigidbody *body, Vector amount);
void MoveBodyTo(Rigidbody* body, Vector position);
void RotateBody(Rigidbody* body, double amount);
void RotateBodyTo(Rigidbody* body, double angle);

void AddForce(Rigidbody* body, Vector amount);

AABB GetBodyAABB(Rigidbody* body);

/// <summary>
/// �����˶�����
/// </summary>
void RigidBodyStep(Rigidbody* body, double time, Vector gravity, int iterations);

/// <summary>
/// ʹ���������ȶ���ò��û�����
/// </summary>
void Stabilizer(Rigidbody* body);

#endif
