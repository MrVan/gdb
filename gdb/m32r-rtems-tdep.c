/* Target-dependent code for GNU/Linux SPARC.

   Copyright (C) 2003-2013 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include "defs.h"
#include "dwarf2-frame.h"
#include "frame.h"
#include "frame-unwind.h"
#include "gdbtypes.h"
#include "regset.h"
#include "gdbarch.h"
#include "gdbcore.h"
#include "osabi.h"
#include "regcache.h"
#include "solib-rtems.h"
#include "symtab.h"
#include "trad-frame.h"
#include "tramp-frame.h"
#include "xml-syscall.h"

static void
m32r_rtems_init_abi (struct gdbarch_info info, struct gdbarch *gdbarch)
{
  struct gdbarch_tdep *tdep = gdbarch_tdep (gdbarch);

  set_solib_rtems_fetch_link_map_offsets
    (gdbarch, rtems_ilp32_fetch_link_map_offsets);
}

/* Provide a prototype to silence -Wmissing-prototypes.  */
extern void _initialize_m32r_rtems_tdep (void);

void
_initialize_m32r_rtems_tdep (void)
{
  gdbarch_register_osabi (bfd_arch_m32r, 0, GDB_OSABI_RTEMS,
                          m32r_rtems_init_abi);
}
