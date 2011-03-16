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
# ident	"@(#)stf.shlib	1.2	07/04/12 SMI"
#

#
# This file is for bourne shell functionality only.
# Any ksh functionality must go into stf.kshlib.
# stf.kshlib includes this file, so any code here must
# work for ksh also or the sharable code must be moved
# to a different (new) common file
#

STF_PASS=0
STF_FAIL=1
STF_UNRESOLVED=2
STF_NOTINUSE=3
STF_UNSUPPORTED=4
STF_UNTESTED=5
STF_UNINITIATED=6
STF_NORESULT=7
STF_WARNING=8
STF_TIMED_OUT=9
STF_OTHER=10

# do this to use the names: eval echo \$STF_RESULT_NAME_${result}
STF_RESULT_NAME_0="PASS"
STF_RESULT_NAME_1="FAIL"
STF_RESULT_NAME_2="UNRESOLVED"
STF_RESULT_NAME_3="NOTINUSE"
STF_RESULT_NAME_4="UNSUPPORTED"
STF_RESULT_NAME_5="UNTESTED"
STF_RESULT_NAME_6="UNINITIATED"
STF_RESULT_NAME_7="NORESULT"
STF_RESULT_NAME_8="WARNING"
STF_RESULT_NAME_9="TIMED_OUT"
STF_RESULT_NAME_10="OTHER"
