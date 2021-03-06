#ifndef IO_FILE_H_
#define IO_FILE_H_

#include "nge_common.h"

/* PSP与win32文件读写统一接口 */
#ifdef _PSP
#include <pspiofilemgr.h>
#define IO_RDONLY PSP_O_RDONLY
#define IO_WRONLY PSP_O_RDWR
#define IO_APPEND PSP_O_APPEND

#define IO_SEEK_CUR PSP_SEEK_CUR
#define IO_SEEK_END PSP_SEEK_END
#define IO_SEEK_SET PSP_SEEK_SET
#else
#define IO_RDONLY 0
#define IO_WRONLY 1
#define IO_APPEND 2

#define IO_SEEK_CUR SEEK_CUR
#define IO_SEEK_END SEEK_END
#define IO_SEEK_SET SEEK_SET
#endif

#ifdef __cplusplus
extern "C"{
#endif

/**
 *打开(本地磁盘)文件
 *@param[in] fname 文件名
 *@param[in] flag 打开标志(IO_RDONLY,IO_WRONLY,IO_APPEND的一种)
 *@return int,文件句柄,读写均用此文件句柄进行操作
 */
	NGE_API int io_fopen(const char* fname,int flag);

/**
 *读文件，与fread类似，总读取字节数为 count * size，返回值是对应于count的实际读取数
 *@param[in] buffer 保存读取数据的缓存
 *@param[in] count 读取的单个块的个数
 *@param[in] size 读取的单个块大小
 *@param[in] handle 文件句柄
 *@return,实际读取数量
 */
	NGE_API int io_fread(void* buffer,int count,int size,int handle);

/**
 *写文件，与fwrite类似，总写入字节数为 count * size，返回值是对应于count的实际写入数
 *@param[in] buffer 待写数据的缓存
 *@param[in] count 待写数据单个块的个数
 *@param[in] size 待写数据单个块的大小
 *@param[in] handle 文件句柄
 *@return,实际写入数量
 */
	NGE_API int io_fwrite(void* buffer,int count,int size,int handle);

/**
 *文件指针偏移设置,与fseek类似
 *@param[in] handle 文件句柄
 *@param[in] offset 偏移量
 *@param[in] flag seek标志,IO_SEEK_CUR,IO_SEEK_END,IO_SEEK_SET
 *@return int,返回0成功,-1失败
 */
	NGE_API int io_fseek(int handle,int offset,int flag);

/**
 *获得当前文件偏移值
 *@param[in] handle 文件句柄
 *@return int 文件偏移值
 */
	NGE_API int io_ftell(int handle);

/**
 *关闭文件
 *@param[in] handle 文件句柄
 *@return int,-1失败
 */
	NGE_API int io_fclose(int handle);

/**
 *文件大小
 *@param[in] handle 文件句柄
 *@return int,文件大小
 */
	NGE_API int io_fsize(int handle);

#ifdef __cplusplus
}
#endif

#endif
