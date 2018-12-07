/*
Copyright (C) 2012 - 2015 Evan Teran
                          evan.teran@gmail.com

Copyright (C) 1995-2003,2004,2005,2006,2007,2008,2009,2010,2011
                   Free Software Foundation, Inc.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ELF_NHDR_20121007_H_
#define ELF_NHDR_20121007_H_

#include "elf_types.h"

/* Note section contents.  Each entry in the note section begins with
   a header of a fixed form.  */

struct elf32_nhdr {
	elf32_word n_namesz; /* Length of the note's name.  */
	elf32_word n_descsz; /* Length of the note's descriptor.  */
	elf32_word n_type;   /* Type of the note.  */
};

struct elf64_nhdr {
	elf64_word n_namesz; /* Length of the note's name.  */
	elf64_word n_descsz; /* Length of the note's descriptor.  */
	elf64_word n_type;   /* Type of the note.  */
};

/* Known names of notes.  */

/* Solaris entries in the note section have this name.  */
#define ELF_NOTE_SOLARIS "SUNW Solaris"

/* Note entries for GNU systems have this name.  */
#define ELF_NOTE_GNU "GNU"

/* Defined types of notes for Solaris.  */

/* Value of descriptor (one word) is desired pagesize for the binary.  */
enum {
	ELF_NOTE_PAGESIZE_HINT = 1,
};

/* Defined note types for GNU systems.  */

/* ABI information.  The descriptor consists of words:
   word 0: OS descriptor
   word 1: major version of the ABI
   word 2: minor version of the ABI
   word 3: subminor version of the ABI
*/
enum {
	NT_GNU_ABI_TAG = 1,
	ELF_NOTE_ABI   = NT_GNU_ABI_TAG, /* Old name.  */
};

/* Known OSes.  These values can appear in word 0 of an
   NT_GNU_ABI_TAG note section entry.  */
enum {
	ELF_NOTE_OS_LINUX    = 0,
	ELF_NOTE_OS_GNU      = 1,
	ELF_NOTE_OS_SOLARIS2 = 2,
	ELF_NOTE_OS_FREEBSD  = 3,
};

enum {
	/* Synthetic hwcap information.  The descriptor begins with two words:
	   word 0: number of entries
	   word 1: bitmask of enabled entries
	   Then follow variable-length entries, one byte followed by a
	   '\0'-terminated hwcap name string.  The byte gives the bit
	   number to test if enabled, (1U << bit) & bitmask.  */
	NT_GNU_HWCAP        = 2,
	
	NT_GNU_BUILD_ID     = 3, /* Build ID bits as generated by ld --build-id. The descriptor consists of any nonzero number of bytes.  */
	NT_GNU_GOLD_VERSION = 4, /* Version note generated by GNU gold containing a version string.  */
};

#endif
