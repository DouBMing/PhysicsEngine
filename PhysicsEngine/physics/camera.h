#ifndef _camera_h
#define _camera_h

#include "vector.h"
#include "entity.h"
#include "list.h"

/// <summary>
/// ����������ӽǿ��Ƽ���Ⱦ
/// </summary>
typedef struct camera
{
	Vector position;
	double scale;
	/// <summary>
	/// ��Ļԭ��
	/// </summary>
	Vector screenOrigin;
}Camera;

/// <summary>
/// ��ʼ�����
/// </summary>
void InitCamera();

/// <summary>
/// ��ȡ��Ļԭ��
/// </summary>
/// <returns></returns>
Vector GetScreenOrigin();
/// <summary>
/// ��ȡ��������
/// </summary>
Vector GetWorldPosition(Vector screenPosition);
/// <summary>
/// ��ȡ��Ļ����
/// </summary>
Vector GetScreenPosition(Vector worldPosition);

/// <summary>
/// �������
/// </summary>
void CameraScale(int event);
/// <summary>
/// ����ƶ�����
/// </summary>
void CameraControl(int key, int event);

/// <summary>
/// �ڵ��޳����ų�����������
/// </summary>
void OcclusionCulling(List* entityList);
/// <summary>
/// ��Ⱦ
/// </summary>
void Render(List* entityList);
/// <summary>
/// ��ȡ���ڻ��Ƶĸ���
/// </summary>
void ScaleBody(Rigidbody* body);

#endif