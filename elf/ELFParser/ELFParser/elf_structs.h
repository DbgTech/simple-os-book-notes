#ifndef _ELF_STRUCTS_H_
#define _ELF_STRUCTS_H_



typedef unsigned long	Elf32_Addr;
typedef unsigned short	Elf32_Half;
typedef unsigned long	Elf32_Off;
typedef unsigned int	Elf32_Word;
typedef int				Elf32_SWord;

////
#define		ELF_SIGN	0x464C457F
#define		EV_CURRENT  1
enum ELFCLASS
{
	ELFCLASSNONE = 0,	// �Ƿ�Ŀ���ļ�
	ELFCLASS32,			// 32λĿ���ļ�
	ELFCLASS64,			// 64λĿ���ļ�
};

enum ELFDATA
{
	ELFDATANONE = 0,	// �Ƿ������ʽ
	ELFDATA2LSB,		// LSB���루С�ֽ���
	ELFDATA2MSB,		// MSB���루���ֽ���
};

typedef struct  
{
	unsigned int ei_sign;	// 'FLE0x7f' = '464C457F'
	unsigned char ei_class;	// ELFCLASS32
	unsigned char ei_data;	// ELFDATA2LSB С�ֽ������
	unsigned char ei_ver;	// EV_CURRENT = 1
	unsigned char ei_pad[7];// ��չ�ֽڣ����Ϊ0
}Inner_Ident;

// 
enum ElfType
{
	ET_NONE = 0,		// δ֪�ļ�����
	ET_REL,				// ���ض�λ�ļ�
	ET_EXEC,			// ��ִ���ļ�
	ET_DYN,				// ��̬���ӿ��ļ�
	ET_CORE,			// Core�ļ�
	ET_LOPROC,			// �ض��������ļ���չ�±߽�
	ET_HIPROC,			// �ض��������ļ���չ�ϱ߽�
};

enum ElfMachine
{
	EM_NONE = 0,		// δ֪��ϵ�ṹ
	EM_M32,				// AT&T WE32100
	EM_SPARC,			// Sparc
	EM_386,				// Intel Arch
	EM_68K,				// Motorola 68000
	EM_88K,				// Motorola 88000
	EM_860,				// Intel 80860 (IA64?)
	EM_MIPS,			// Mips RS3000 Big-Endian
	EM_MIPS_RS4_BE,		// Mips RS4000 Big-Endian
	RESERVED,			// 11 ~ 16����δ��
};

#define		EI_NIDENT	16
typedef struct  
{
	unsigned char e_ident[EI_NIDENT];		// ͳһ��ʶ�����������
	Elf32_Half e_type;			// ELF�ļ�������
	Elf32_Half e_machine;		// ��������ϵ�ṹ
	Elf32_Word e_version;		// �汾�� EV_CURRENT
	Elf32_Addr e_entry;			// ������ڵ������ַ���ǿ�ִ�г�����ֶ�Ϊ0
	Elf32_Off  e_phoff;			// program header table�ļ���ƫ��
	Elf32_Off  e_shoff;			// section header table�ļ���ƫ��
	Elf32_Word e_flags;			// �������ض���־λ������Intel�ܹ�Ϊ0
	Elf32_Half e_ehsize;		// ELF�ļ�ͷ�Ĵ�С���ֽ�Ϊ��λ
	Elf32_Half e_phentsize;		// ����ͷ����ÿһ���С���ֽ�Ϊ��λ
	Elf32_Half e_phnum;			// ����ͷ���б�����
	Elf32_Half e_shentsize;		// ��ͷ��ÿһ�������С���ֽ�Ϊ��λ
	Elf32_Half e_shnum;			// ��ͷ���б�����
	Elf32_Half e_shstrndx;		// ��ͷ��������������Ӧ�ı��������������ΪSHN_UNDEF
}Elf32_Ehdr;

enum SectionHeaderIndex
{
	SHN_UNDEF = 0,				// δ���壬�����ڽ�����
	
	SHN_LORESERVE = 0xFF00,		// �������������������� 
	//SHN_LOPROC = 0xFF00		// Ϊ���������ƽڱ�����������������
	SHN_HIPROC = 0xFF1F,		// Ϊ���������ƽڱ�����������������
	SHN_ABS = 0xFFF1,			// �����ж�������о���ֵ���������ض�λ�ı�
	SHN_COMMON = 0xFFF2,		// ���ж��幫�����ţ���δ�����C�ⲿ������
	SHN_HIRESERVE = 0xFFFF,		// �������������������
};

enum SectionType
{
	SHT_NULL = 0,				// ��ʾ��Ч�Ľ�ͷ
	SHT_PROGBITS = 1,			// ������Ϣ�ɳ����壬��ʽ�ͺ����г������
	SHT_SYMTAB = 2,				// ���ű����ڴ���Ŀ���ļ�ʱ�༭���ӣ������ķ��ű�
	SHT_STRTAB = 3,				// �ַ�����һ��ELF�п��԰������
	SHT_RELA = 4, 				// �ض�λ�ڣ����д���ȷ�������ض�λ��
	SHT_HASH = 5,				// ����һ�Ź�ϣ����̬������ʹ�õķ��Ź�ϣ��
	SHT_DYNAMIC = 6,			// ���ڰ�����̬������Ϣ
	SHT_NOTE = 7,				// ���ڰ�����Ϣ������ĳ�ַ�ʽ����Ǳ��ļ�
	SHT_NOBITS = 8,				// �����ý�����Ϊ�գ��ڲ���ռ��ʵ�ʿռ�
	SHT_REL = 9,				// һ���ض�λ�ڣ�����ȷ�������ض�λ����ܰ��������
	SHT_SHLIB = 10,				// ����ֵ����δʹ��
	SHT_DYNSYM = 11,			// ���ű��洢�����ڼ䣨��̬���ӣ�ʹ�÷���
	SHT_LOPROC = 0x70000000,	// Ϊ���⴦������������������ֵ�±߽�
	SHT_HIPROC = 0x7FFFFFFF,	// Ϊ���⴦������������������ֵ�ϱ߽�
	SHT_LOUSER = 0x80000000,	// ΪӦ�ó������������±߽�
	SHT_HIUSER = 0xFFFFFFFF,	// ΪӦ�ó������������ϱ߽� 
};

#define	SHF_WRITE			0x1			// �������й����п�д
#define	SHF_ALLOC			0x2			// ���������ڽ���������Ҫռ���ڴ�
#define	SHF_EXECINSTR		0x4			// �˽�������ָ�����
#define	SHF_MASHPROC		0xF0000000	// ���б���ֵ������λΪ����λ


typedef struct  
{
	Elf32_Word sh_name;			// ���ڵ����֣�"�ַ�����"���е�����ֵ
	Elf32_Word sh_type;			// ���ڵ�����
	Elf32_Word sh_flags;		// ���ڵ�һЩ���ԣ���һϵ�б���λ���
	Elf32_Addr sh_addr;			// ӳ�䵽���̿ռ��У�ָ��ӳ�����ʼ��ַ
	Elf32_Off  sh_offset;		// ��������λ�ã����ýڵ�һ���ֽ����ļ���λ��
	Elf32_Word sh_size;			// ָ���ڵĴ�С����λΪ�ֽ�
	Elf32_Word sh_link;			// ����ֵ��ִ���ͷ���б�������Ӧλ��
	Elf32_Word sh_info;			// �ڵĸ�����Ϣ����ͬ���ͽڣ����ֶ����岻ͬ
	Elf32_Word sh_addralign;	// ������ζ��룬��sh_addr��������sh_addralign
	Elf32_Word sh_entsize;		// ��Щ������Ϊ��ÿ�ű��С�̶����ó�Աָ�������С
}Elf32_Shdr;

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	   sh_type			sh_link			        sh_info
	SHT_DYNAMIC   ��������Ŀ���ַ�����             0
				  �ڽ�ͷ������Ӧ������
	SHT_HASH      ������Hash��ķ��ű�             0
				  �ڽ�ͷ������Ӧ����

	SHT_REL/	  ��Ӧ���ű��ڽ�ͷ���е�   ���ض�λ����Ӧ�õ�
	SHT_RELA      ����ֵ                   Ŀ����ڱ�ͷ��������

	SHT_SYMTAB/   ����ַ�����Ľ�ͷ����	���ű������һ�����ط���
	SHT_DYNSYM								������ֵ�� 1
	
		����       SHN_UNDEF						0
 --------------------------------------------------------------*/

/*
 ��������ֵΪ0�Ľ�ͷ�����������ʵ�����ݣ�ֻ��һ���հױ��ֵ���£�
	sh_type ֵΪSHT_NULL
	sh_link ֵΪSHN_UNDEF
	
	������ԱֵȫΪ0
 */

typedef struct  
{
	Elf32_Word st_name;		// �������֣��ַ���������ֵ
	Elf32_Addr st_value;	// ���ŵ�ֵ
	Elf32_Word st_size;		// ���ŵĴ�С
	unsigned char st_info;	// ���ŵ����ͺ����ԣ�һϵ�б���λ����
	unsigned char st_other;	// ��δʹ�ã�ֵΪ0
	Elf32_Half st_shndx;	// ָ���������
}Elf32_Sym;

typedef struct  
{
	Elf32_Addr r_offset;	// �����ݳ�Ա�����ض�λ������λ��
	Elf32_Word r_info;		// �ض�λ�����õķ��ű�����
}Elf32_Rel;

typedef struct  
{
	Elf32_Addr r_offset;
	Elf32_Word r_info;
	Elf32_SWord r_addend;	// ָ��һ�����������ڼ�����Ҫ�ض�λ�����ֵ
}Elf32_Rela;


//////////////////////////////////////////////////////////////////////////

// 
enum SegmentType
{
	PT_NULL = 0,				// ��ʾ������ͷδʹ��
	PT_LOAD = 1,				// ִ��һ����װ�ض�
	PT_DYNAMIC = 2,				// ����Ϊ��̬������Ϣ
	PT_INTERP = 3,				// ELF������·������null��β���ַ���
	PT_NOTE = 4,				// ������Ϣ�ĶΣ���null��β�ַ���
	PT_SHLIB = 5,				// ������δ����
	PT_PHDR = 6,				// ����ͷ�����ļ����ڴ��е�λ�úʹ�С
	PT_LOPROC = 0x70000000,		// Ϊ�ض�����������
	PT_HIPROC = 0x7FFFFFFF,		// 
};

enum SegmentPermissions
{
	PF_NONE = 0,		// ���κ�Ȩ��
	PF_X = 1,			// ��ִ��Ȩ�ޣ�ʵ��Ϊ�ɶ�����ִ��
	PF_W = 2,			// ��д
	PF_R = 4,			// �ɶ�
};

// �ɶ��Ϳ�ִ����ͨ�õģ����ɶ��Ϳ���ִ�У�ͬʱ��ִ�б�Ȼ�ɶ�
// ��дȨ�������Ȩ�ޣ����Ը����������������˿�дȨ�ޣ�����Ȩ�޾Ͷ�����

// ��ִ���ļ�����Ŀ���ļ��ĳ���ͷ��ÿһ���Ϊ����ͷ
// ÿһ������ͷ������һ���Σ���һ������׼��ִ�г������Ϣ
// ����ͷֻ�Կ�ִ���ļ�����Ŀ���ļ������壬����ִ�е�ELF
typedef struct  
{
	Elf32_Word p_type;		// ������ͷ������������
	Elf32_Off  p_offset;	// �����������ļ���λ�ã�����ļ���ͷƫ����
	Elf32_Addr p_vaddr;		// �����ڽ��̿ռ�����ʼ�����ַ
	Elf32_Addr p_paddr;		// �ڽ��̿ռ��е���ʼ�����ַ��һ�㲻��
	Elf32_Word p_filesz;	// �ļ�����ռ�ռ�
	Elf32_Word p_memsz;		// �ڴ�����ռ�ռ䣬һ�����p_filesz
	Elf32_Word p_flags;		// ����������
	Elf32_Word p_align;		// �ڴ����ֵ
}Elf32_Phdr;

// �� Segment
// һ���������ɸ�����ɣ���������ͷ�������Ľڵ����⣬����װ�غͽڲ�û��̫���ϵ
// .text Ϊ����Σ�һ�����.text/.rodata/.hash/.dynsym/.dynstr/.plt/.rel.got��
// ���ݶ�����Ͱ���.data / .dynamic / .got / .bss��

enum DynamicType
{							//       EXE    SO
	DT_NULL = 0,			// ����  ����   ����   ��Ϊ����������
	DT_NEEDED = 1,			// d_val ��ѡ   ��ѡ   ָ������Ŀ����֣����԰���������
	DT_PLTRELSZ = 2,		// d_val ��ѡ   ��ѡ   �������ӱ�����ض�λ���ܴ�С���ֽ�Ϊ��λ
	DT_PLTGOT = 3,			// d_ptr ��ѡ   ��ѡ   �������ӱ��ȫ��ƫ��������Ӧ�ĵ�ַ
	DT_HASH = 4,			// d_ptr ����   ����   ���Ź�ϣ��ĵ�ַ
	DT_STRTAB = 5,			// d_ptr ����   ����   �ַ�����ĵ�ַ���������Ϳ�����
	DT_SYMTAB = 6,			// d_ptr ����   ����   ���ű�ĵ�ַ
	DT_RELA = 7,			// d_ptr ����   ��ѡ   �ض�λ��ĵ�ַ���洢��ʾ�ļ���
	DT_RELASZ = 8,			// d_val ����   ��ѡ   DT_RELA�ض�λ��Ĵ�С���ֽ�Ϊ��λ
	DT_RELAENT = 9,			// d_val ����   ��ѡ   DT_RELA��Ӧ�ض�λ�����С
	DT_STRSZ = 10,			// d_val ����   ����   �ַ�����Ĵ�С
	DT_SYMENT = 11,			// d_val ����   ����   ���ű���Ĵ�С���ֽ�Ϊ��λ
	DT_INIT = 12,			// d_ptr ��ѡ   ��ѡ   ��ʼ��������ַ
	DT_FINI = 13,			// d_ptr ��ѡ   ��ѡ   ��ֹ�����ĵ�ַ
	DT_SONAME = 14,			// d_val ����   ��ѡ   �ַ������е�ƫ����������Ŀ������
	DT_RPATH = 15,			// d_val ��ѡ   ����   �ַ������е�ƫ�����������������ļ�·����
	DT_SYMBOLIC = 16,		// ����  ����   ��ѡ   ������̬�������������ʱ�㷨
	DT_REL = 17,			// d_ptr ����   ��ѡ   ��DT_RELA���ƣ�ָ���ض�λ��
	DT_RELSZ = 18,			// d_val ����   ��ѡ   DT_REL��Ӧ�ض�λ��Ĵ�С
	DT_RELENT = 19,			// d_val ����   ��ѡ   DT_REL��Ӧ�ض�λ����Ĵ�С
	DT_PLTREL = 20,			// d_val ��ѡ   ��ѡ   �������ӱ������õ��ض�λ�������
	DT_DEBUG = 21,			// d_ptr ��ѡ   ����   ���ڵ���
	DT_TEXTREL = 22,		// ����  ��ѡ   ��ѡ   �Ƿ�����޸�ֻ����
	DT_JMPREL = 23,			// d_ptr ��ѡ   ��ѡ   ָ���뺯�����ӱ����������ض�λ���ַ
	DT_BIND_NOW = 24,		// ����  ��ѡ   ��ѡ   ������֣����ڳ���ʼִ��ǰ����������ض�λ����
	DT_LOPROC = 0x70000000,	// δ����δ���� δ���� Ϊ����������
	DT_HIPROC = 0x7FFFFFFF,	// δ����δ���� δ���� Ϊ����������
};

typedef struct  
{
	Elf32_SWord d_tag;		// d_tag������d_un�Ľ���
	union {
		Elf32_Word d_val;	// ����������
		Elf32_Addr d_ptr;	// ������̿ռ���ĵ�ַ
	}d_un;	
}Elf32_Dyn;

//extern Elf32_Dyn _DYNAMIC[];

#endif