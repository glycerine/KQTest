#
# CDDL HEADER START
#
# The contents of this file are subject to the terms of the
# Common Development and Distribution License (the "License").
# You may not use this file except in compliance with the License.
#
# You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
# or http://www.opensolaris.org/os/licensing.
# See the License for the specific language governing permissions
# and limitations under the License.
#
# When distributing Covered Code, include this CDDL HEADER in each
# file and include the License file at usr/src/OPENSOLARIS.LICENSE.
# If applicable, add the following below this CDDL HEADER, with the
# fields enclosed by brackets "[]" replaced with your own identifying
# information: Portions Copyright [yyyy] [name of copyright owner]
#
# CDDL HEADER END
#

#
# Copyright 2007 Sun Microsystems, Inc.  All rights reserved.
# Use is subject to license terms.
#
# ident	"@(#)Makefile	1.4	07/10/09 SMI"
#

STF_ROOT_CONFIGURE=
STF_USER_CONFIGURE=

STF_ROOT_SETUP=setup
STF_USER_SETUP=

STF_ROOT_CLEANUP=cleanup
STF_USER_CLEANUP=

STF_ROOT_TESTCASES=zpool_upgrade_001_pos \
zpool_upgrade_002_pos \
zpool_upgrade_003_pos \
zpool_upgrade_004_pos \
zpool_upgrade_005_neg \
zpool_upgrade_006_neg \
zpool_upgrade_007_pos \
zpool_upgrade_008_pos \
zpool_upgrade_009_neg

STF_USER_TESTCASES=

STF_ENVFILES=zpool_upgrade.cfg
STF_INCLUDES=zpool_upgrade.kshlib

STF_BUILD_SUBDIRS=blockfiles

STF_DONTBUILDMODES=true

include ${STF_TOOLS}/Makefiles/Makefile.master
