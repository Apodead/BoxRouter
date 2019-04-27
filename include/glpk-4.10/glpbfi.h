/* glpbfi.h (basis factorization interface) */

/*----------------------------------------------------------------------
-- This code is part of GNU Linear Programming Kit (GLPK).
--
-- Copyright (C) 2000, 01, 02, 03, 04, 05, 06 Andrew Makhorin,
-- Department for Applied Informatics, Moscow Aviation Institute,
-- Moscow, Russia. All rights reserved. E-mail: <mao@mai2.rcnet.ru>.
--
-- GLPK is free software; you can redistribute it and/or modify it
-- under the terms of the GNU General Public License as published by
-- the Free Software Foundation; either version 2, or (at your option)
-- any later version.
--
-- GLPK is distributed in the hope that it will be useful, but WITHOUT
-- ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
-- or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public
-- License for more details.
--
-- You should have received a copy of the GNU General Public License
-- along with GLPK; see the file COPYING. If not, write to the Free
-- Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
-- 02110-1301, USA.
----------------------------------------------------------------------*/

#ifndef _GLPBFI_H
#define _GLPBFI_H

#define bfi_create_binv       glp_bfi_create_binv
#define bfi_factorize         glp_bfi_factorize
#define bfi_ftran             glp_bfi_ftran
#define bfi_btran             glp_bfi_btran
#define bfi_update_binv       glp_bfi_update_binv
#define bfi_delete_binv       glp_bfi_delete_binv

#ifndef _GLPBFI_DEFINED
#define _GLPBFI_DEFINED
typedef struct { int none_; } BFI;
#endif

BFI *bfi_create_binv(void);
/* create factorization of the basis matrix */

int bfi_factorize(BFI *binv, int m,
      void *info, int (*col)(void *info, int j, int rn[], double bj[]));
/* compute factorization of the basis matrix */

void bfi_ftran(BFI *binv, double x[], int save);
/* perform forward transformation (FTRAN) */

void bfi_btran(BFI *binv, double x[]);
/* perform backward transformation (BTRAN) */

int bfi_update_binv(BFI *binv, int j);
/* update factorization of the basis matrix */

void bfi_delete_binv(BFI *binv);
/* delete factorization of the basis matrix */

#endif

/* eof */
