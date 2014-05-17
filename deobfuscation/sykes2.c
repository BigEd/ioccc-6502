#include <stdio.h>
#include <string.h>
#include <curses.h>

int		d, C, Z, I, D, B, V, S, i = 0xc000, t, s, o, h, z, O = 256,
		n = 0xffff, l = 128, f = 255, e, w;
unsigned char  *p, m[65536], a, x, y, k, *u;


	/* j is 528 characters  */
unsigned char *j =
  " ./  p/ 7 ] . 6 6 p     t7      r(0)1*+2,4WgcovGn^f_NVO>F?T\\swldiHZYI9QJ"
  "RCKSL[b<D8AP:;a@`BXq3j=- HZYI9QJRCKSL[b<D8AP:;a@`BX   57  ;  ;      ;   ;   "
  "     ;                                                                      "
  "                                )<   <% ><%  <% '<   <% +<   <% 7$  ($A @$A "
  "($A &$   $A *$   $A C2   2; =2; 62; '2   2; +2   2; D#   #B ?#B 6#B &#   #B "
  "*#   #B  F  HFG 1 L HFG 'F  HFG NFM  F  :89 :89 J8I :89 &8  :89 +8K :89 .,  "
  ".,/ 5,0 .,/ ',   ,/ +,   ,/ -E  -E3 4E  -E3 &E   E3 *E   E3 2133024425660788"
               ;

R(x)
{
	Z = x ? 0 : 2;
	S = x & l;
}

K(x)
{
	R(x - *p);
	C = x < *p ? 0 : 1;
}

A()
{
	R(t = m[n & ++k + O]);
	C = t & 1;
	Z = t & 2;
	I = t & 4;
	D = t & 8;
	B = t & 16;
	V = t & 64;
}

X()
{
	m[n & k-- + O] = d / O;
	m[n & k-- + O] = d;
}

N()
{
	X();
	m[n & k-- + O] = C | Z | I | D | B | V | S | 32;
	I = 4;
	d = (t = n - 1, d += 0, m[n & t] + m[n & t + 1] * O);
}

#define c argc
#define v argv
#define g filehandle

mainloop(int c)
{
	FILE *g;
	for (;;) {
		o++ % (c * 4) ? h : (h = wgetch(stdscr), h - (-1) ? (m[n & 162] = h | l) : 0);
		if (!w) {
		  /* 59408 is PIA 1 */
		  s = (m[n & 59408] |= z ? l : 0) & 15;
		  m[n & 59410] = ~(
                                         h - (-1) ?
                                           (s ^ 8 ? 0 : j[h | l] & 1) | (j[h] / 8 - 5 - s ? 0 : 1 << j[h] % 8)
                                           : 0
				   );
		}
		o % c | I || N();
		p = m + O + O + m[n & l - 9];
		t = d % 65493;  /* 0xffd5 is LOAD */
		i = m[n & d++]; /* i is the fetched instruction */
		if (w + t < 4) {
			if (*p && (u = strchr(++p, 34))) {
				*u = 0;
				m[n & l - 9] = u - m + 1;
				if (g = fopen(p, t ? j + 61 : j + 32)) {
					i = 1025 - t;
					if (!t) {
						(s = fgetc(g));
						for ((s = fgetc(g)); (s = fgetc(g)) + 1; m[n & i++] = s);
						for (p = m + 42; p < m + 47;
							) {
							*p++ = i % O;
							*p++ = i / O;
						}
					}
					for (; t; fputc(m[n & i], g))
						t = m[n & ++i] ? 3 : t - 1;
					fclose(g);
				}
			}
			i = 96;
		}

                /* j is a multi-purpose lookup table */
		t = j[i / 2 & 14 | i & 1 | O + O] & 15;

                /* poor man's case statement, switching on t */
                /* e must be effective address and we must be switching on addressing modes */
		e = t-- ?
                    t-- ?
                    t-- ?
                    t-- ?
                    t-- ?
                    t-- ?
                    t-- ?
                    t-- ?
		  (t = d, d += 2, m[n & t] + m[n & t + 1] * O) + (i - 190 ? x : y) /* 190 is BE - uniquely abs,Y */
                  : (t = d, d += 2, m[n & t] + m[n & t + 1] * O) + y
                  : f & m[n & d++] + (i - 150 && i - 182 ? x : y) /* the two zp,Y opcodes */
                  : (t = m[n & d], d += 1, m[n & t] + m[n & t + 1] * O) + y
                  : (t = d, d += 2, m[n & t] + m[n & t + 1] * O)
                  : m[n & d++]
                  : d++
                  : (t = m[n & d] + x & f, d += 1, m[n & t] + m[n & t + 1] * O)
                  : &a - m;

		p = e + m;
		s = i >> 6;
		t = j[i + O] - 35;

		/* another case statement - the main instruction emulation*/
		t-- ? t-- ? t-- ? t-- ?
		t-- ? t-- ? t-- ? t-- ?
		t-- ? t-- ? t-- ? t-- ?
		t-- ? t-- ? t-- ? t-- ?
		t-- ? t-- ? t-- ? t-- ?
		t-- ? t-- ? t-- ? t-- ?
		t-- ? t-- ? t-- ? t-- ?
		t-- ? t-- ? t-- ? t-- ?
		t-- ? t-- ? t-- ? t-- ?
		t-- ? t-- ? t-- ? t-- ?
		t-- ? t-- ? t-- ? t-- ?
		0
		  : R(a = y)
		  : (k = x)
		  : (R(a = x))
		  : (R(x = k))
		  : (R(y = a))
		  : (R(x = a))
		  : (*p = y) /* STY */
		  : (*p = x)
		  : (*p = a)
		  : (t = a - *p - 1 + C, C = t & O ? 0 : 1, V = ((a ^ *p) & (a ^ t) & l) / 2, R(a = t & f))
		  : (d = m[n & ++k + O], d += m[n & ++k + O] * O + 1)
		  : (A(), d = m[n & ++k + O], d |= m[n & ++k + O] * O)
		  : (t = *p, R(*p = *p / 2 | C * l), C = t & 1)
		  : (t = *p, R(*p = *p * 2 | C), C = t / l)
		  : A()
		  : R(a = m[n & ++k + O])
		  : (m[n & k-- + O] = C | Z | I | D | B | V | S | 32)
		  : (m[n & k-- + O] = a)
		  : (R(a |= *p))
		  : (C = *p & 1, R(*p /= 2))
		  : (R(y = *p))
		  : R(x = *p)
		  : R(a = *p)
		  : (s = (t = --d, d += 1, m[n & t] + m[n & t + 1] * O), X(), d = s)
		  : (d = i & 32 ? (t = e, d += 0, m[n & t] + m[n & t + 1] * O) : e)
		  : R(++y)
		  : R(++x)
		  : R(++*p)
		  : R(a ^= *p)
		  : R(--y)
		  : R(--x)
		  : R(--*p)
		  : K(y)
		  : K(x)
		  : K(a)
		  : (*(s ? s - 1 ? s - 2 ? &D : &V : &I : &C) = 0)
		  : (*(s ? s - 1 ? s - 2 ? &D : &V : &I : &C) = (s ? s - 1 ? s - 2 ? 8 : 8 : 4 : 1))
		  : (d--, B = 16, N())
		  : (R(a & *p), V = *p & 64, S = *p & l)
		  : !(s ? s - 1 ? s - 2 ? Z : C : V : S) && (d += *p & l ? *p - O : *p)
		  : (s ? s - 1 ? s - 2 ? Z : C : V : S) && (d += *p & l ? *p - O : *p)
		  : (C = *p / l, R(*p *= 2))
		  : R(a &= *p)
		  : (t = a + *p + C, C = t & O ? 1 : 0, V = (~(a ^ *p) & (a ^ t) & l) / 2, R(a = t & f));

		t = e ^ O * O / 2;
		if (t < 1000) { /* conditionally update screen */
			s = *p % l;
			i = ((1U) << ((10) + 8));
			*p > s ? wattr_on(stdscr, (attr_t) (i), ((void *)0))
			       : wattr_off(stdscr, (attr_t) (i), ((void *)0));
			(wmove(stdscr, t / 40, t % 40) == (-1)
                                           ? (-1)
                                           : waddch(stdscr, s + w < 32 ? s + 64 : s > 95 + w ? s - 32 : s)
			 );
		}
	}
}

main(int c, char *v[])
{
	FILE *g;
	m[n & z] = time(0);
	g = fopen(c > 1 ? v[1] : "", j + 32);
	t = i;
	if (!g) {;
		perror(*v);
		exit(1);
	}
	for (; /* load file as given on command line */
             (s = fgetc(g)) + 1;
	     m[n & t++] = s
            );
	w = t & n;
        /* d is initial PC */
	d = w ? i : (t = n - 3, d += C, m[n & t] + m[n & t + 1] * O);
	z = c >2
               ? atoi(v[2]) + 1
               : 4;
	c = z ? n * z / 4 : n;
	nodelay(initscr(), 1);
	curs_set(I);
	cbreak();
	noecho();

	mainloop(c);
}
