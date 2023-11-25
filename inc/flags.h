#ifndef FLAGS_H
#define FLAGS_H

#define FLAG_l  0x01
#define FLAG_R  0x02
#define FLAG_A  0x04
#define FLAG_a  0x08
#define FLAG_G  0x10
#define FLAG_h  0x20
#define FLAG_AT 0x40
#define FLAG_e  0x80
#define FLAG_T  0x100
#define FLAG_1  0x200
#define FLAG_C  0x400
#define FLAG_r  0x800
#define FLAG_t  0x1000
#define FLAG_u  0x2000
#define FLAG_c  0x4000
#define FLAG_S  0x8000

int mx_check_flags(int argc, char *argv[], unsigned short *flags);

#endif

