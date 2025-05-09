dnl Process this file with autoconf to produce a configure script.

AC_REVISION($Revision: 1.10 $)
AC_INIT([Debug Trace Interface],[1.3.0],[],[lib_dti])

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([aux_local])

AC_CONFIG_SRCDIR(src/Makefile.am)
AM_INIT_AUTOMAKE([-Wno-portability tar-pax subdir-objects])

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AM_PROG_CC_C_O
AC_PROG_INSTALL
AC_PROG_LN_S
AM_PROG_INSTALL_STRIP
LT_INIT

CONFIGURE_OPTIONS="$ac_configure_args"
AC_SUBST(CONFIGURE_OPTIONS)

AM_CONDITIONAL(HAVE_GCC, true)

AM_CONDITIONAL(ENABLE_ECOS, false)
AM_CONDITIONAL(ENABLE_LINUX, true)
AM_CONDITIONAL(ENABLE_GENERIC, false)
AM_CONDITIONAL(HAVE_IFXOS_SYSOBJ_SUPPORT, false)

AM_CONDITIONAL(BUILD_DTI_AGENT, false)
AM_CONDITIONAL(BUILD_DTI_CLIENT, false)
AM_CONDITIONAL(DEVICE_GENERIC, false)
AM_CONDITIONAL(INCLUDE_CLI_SUPPORT, false)

AM_CONDITIONAL(ENABLE_DEBUG, false)
AM_CONDITIONAL(HAVE_IFXOS_SYSOBJ_SUPPORT, false)

dnl target options for build
DTI_TARGET_OPTIONS=""

dnl Enable the cc compiler
AM_CONDITIONAL(HAVE_GCC, true)
AC_ARG_ENABLE(have-cc,
	AS_HELP_STRING(
		[--enable-have-cc],
		[Use the cc compiler]
	),
	[
		if test "$enableval" = yes; then
			echo Use the cc compiler
			AM_CONDITIONAL(HAVE_GCC, false)
			AC_SUBST([HAVE_GCC],[no])
		else
			echo Use the gcc compiler
			AM_CONDITIONAL(HAVE_GCC, true)
			AC_SUBST([HAVE_GCC],[yes])
		fi
	],
	[
		AM_CONDITIONAL(HAVE_GCC, true)
		AC_SUBST([HAVE_GCC],[yes])
	]
)

dnl Enable the eCos operating system
AC_ARG_ENABLE(ecos,
	AS_HELP_STRING(
		[--enable-ecos],
		[Enable eCos]
	),
	[
		if test "$enableval" = yes; then
			echo Enable eCos operating system
			AM_CONDITIONAL(ENABLE_LINUX, false)
			AM_CONDITIONAL(ENABLE_GENERIC, false)
			AM_CONDITIONAL(ENABLE_ECOS, true)
		fi
	]
)

dnl Enable the generic operating system
AC_ARG_ENABLE(generic,
	AS_HELP_STRING(
		[--enable-generic],
		[Enable generic OS]
	),
	[
		if test "$enableval" = yes; then
			echo Enable generic operating system
			AM_CONDITIONAL(ENABLE_ECOS, false)
			AM_CONDITIONAL(ENABLE_LINUX, false)
			AM_CONDITIONAL(ENABLE_LINUX, false)
			AM_CONDITIONAL(ENABLE_GENERIC, true)
		fi
	]
)

dnl Enable the DTI client build
AC_ARG_ENABLE(dti-client,
	AS_HELP_STRING(
		[--enable-dti-client],
		[Enable client build]
	),
	[
		if test "$enableval" = yes; then
			echo Enable DTI client build
			AM_CONDITIONAL(BUILD_DTI_CLIENT, true)
			AC_SUBST([BUILD_DTI_CLIENT],[yes])
		else
			AM_CONDITIONAL(BUILD_DTI_CLIENT, false)
			AC_SUBST([BUILD_DTI_CLIENT],[no])
		fi
	]
)

dnl Enable the DTI agent build
AC_ARG_ENABLE(dti-agent,
	AS_HELP_STRING(
		[--enable-dti-agent],
		[Enable agent build]
	),
	[
		if test "$enableval" = yes; then
			echo Enable DTI agent build
			AM_CONDITIONAL(BUILD_DTI_AGENT, true)
			AC_SUBST([BUILD_DTI_AGENT],[yes])
		else
			AM_CONDITIONAL(BUILD_DTI_AGENT, false)
			AC_SUBST([BUILD_DTI_AGENT],[no])
		fi
	]
)

dnl enable Generic device support
AC_ARG_ENABLE(dev-generic,
	AS_HELP_STRING(
		[--enable-dev-generic],[Add Generic support.]
	),
	[
		if test "$enableval" = yes; then
			AM_CONDITIONAL(DEVICE_GENERIC, true)
			AC_SUBST([DEVICE_GENERIC],[yes])
		else
			AM_CONDITIONAL(DEVICE_GENERIC, false)
			AC_SUBST([DEVICE_GENERIC],[no])
		fi
	],
	[
		AM_CONDITIONAL(DEVICE_GENERIC, false)
		AC_SUBST([DEVICE_GENERIC],[no])
	]
)


dnl enable Command Line Interface support
AC_ARG_ENABLE(cli,
	AS_HELP_STRING(
		[--enable-cli],[Add CLI support.]
	),
	[
		if test "$enableval" = yes; then
			AM_CONDITIONAL(INCLUDE_CLI_SUPPORT, true)
			AC_SUBST([INCLUDE_CLI_SUPPORT],[yes])
			DTI_TARGET_OPTIONS="$DTI_TARGET_OPTIONS -DINCLUDE_CLI_SUPPORT"
		else
			AM_CONDITIONAL(INCLUDE_CLI_SUPPORT, false)
			AC_SUBST([INCLUDE_CLI_SUPPORT],[no])
		fi
	],
	[
		AM_CONDITIONAL(INCLUDE_CLI_SUPPORT, false)
		AC_SUBST([INCLUDE_CLI_SUPPORT],[no])
	]
)

AC_ARG_ENABLE(core-statistic,
	AS_HELP_STRING(
		[--enable-core-statistic],
		[Add DTI Statistic support.]
	),
	[
		case $enableval in
		0|no|NO)
			DTI_TARGET_OPTIONS="$DTI_TARGET_OPTIONS -DDTI_INCLUDE_CORE_STATISTICS=0"
			;;
		1|yes|YES)
			DTI_TARGET_OPTIONS="$DTI_TARGET_OPTIONS -DDTI_INCLUDE_CORE_STATISTICS=1"
			;;
		*)
			;;
		esac
	],
)

dnl Enable debugging mode
AC_ARG_ENABLE(debug,
	AS_HELP_STRING(
		[--enable-debug],
		[Compilation with Debug Enable]
	),
	[
		if test "$enableval" = yes; then
			AM_CONDITIONAL(ENABLE_DEBUG, true)
			AC_SUBST([ENABLE_DEBUG],[yes])
			DTI_TARGET_OPTIONS="$DTI_TARGET_OPTIONS -DDTI_DBG"
		else
			AM_CONDITIONAL(ENABLE_DEBUG, false)
			AC_SUBST([ENABLE_DEBUG],[no])
		fi
	],
	[
		AM_CONDITIONAL(ENABLE_DEBUG, false)
		AC_SUBST([ENABLE_DEBUG],[no])
	]
)

dnl Enable error printouts
AC_ARG_ENABLE(error-print,
	AS_HELP_STRING(
		[--enable-error-print],
		[Enable error messages]
	),
	[
		if test "$enableval" = no; then
			DTI_TARGET_OPTIONS="$DTI_TARGET_OPTIONS -DDTI_ERROR_PRINT=0"
			echo "disable error prints"
		else
			echo "enable error prints"
		fi
	],
)

dnl Enable debugging mode
AC_ARG_ENABLE(debug-print,
	AS_HELP_STRING(
		[--enable-debug-print],
		[Enable debug messages]
	),
	[
		if test "$enableval" = no; then
			DTI_TARGET_OPTIONS="$DTI_TARGET_OPTIONS -DDTI_DEBUG_PRINT=0"
		fi
	],
)

dnl set the number of max supported channels
DTI_MAX_SUPPORTED_PORTS_PER_DEVICE_NUM=8
AC_ARG_WITH(dti-max-lines-per-device,
	AS_HELP_STRING(
		[--with-dti-max-lines-per-device=value],
		[DTI max lines per device.]
	),
	[
		if test "$withval" = yes; then
			AC_MSG_ERROR([ Please provide a value for max lines per device]);
		fi
		AC_DEFINE_UNQUOTED(DTI_MAX_SUPPORTED_PORTS_PER_DEVICE_NUM,$withval, [DTI max lines per device])
		AC_SUBST([DTI_MAX_SUPPORTED_PORTS_PER_DEVICE_NUM],[$withval])
	]
)

dnl set the number of max supported devices
DTI_MAX_SUPPORTED_DEVICE_NUM=8
AC_ARG_WITH(dti-max-devices,
	AS_HELP_STRING(
		[--with-dti-max-devices=value],
		[DTI max devices.]
	),
	[
		if test "$withval" = yes; then
			AC_MSG_ERROR([ Please provide a value for the dti max devices]);
		fi
		AC_DEFINE_UNQUOTED(DTI_MAX_SUPPORTED_DEVICE_NUM,$withval, [DTI max devices])
		AC_SUBST([DTI_MAX_SUPPORTED_DEVICE_NUM],[$withval])
	]
)


dnl set the default TCP/IP port for the DTI connection
DTI_TCP_PORT=0
AC_ARG_WITH(dti-tcp-port,
	AS_HELP_STRING(
		[--with-dti-tcp-port=value],
		[Default TCP port for the DTI connection]
	),
	[
		if test "$withval" = yes; then
			AC_MSG_ERROR([ Please provide a new TCP port for the conncetion]);
		fi
		AC_DEFINE_UNQUOTED(DTI_TCP_PORT,$withval, [TCP Port])
		AC_SUBST([DTI_TCP_PORT],[$withval])
	]
)

dnl set DSL Driver include path
DEFAULT_DEV_DRIVER_INCL_PATH='-I/missing/device/driver/include/path'
AC_ARG_ENABLE(dev-driver-include,
	AS_HELP_STRING(
		[--enable-dev-driver-include= -I/path/to/your/device/driver],
		[Set the device driver include path]
	),
	[
	 if test -n "$enableval"; then
		 AC_SUBST([DEV_DRIVER_INCL_PATH],
					 [$enableval])
	 else
		 AC_SUBST([DEV_DRIVER_INCL_PATH],
					 [$DEFAULT_DEV_DRIVER_INCL_PATH])
	 fi
	]
)

dnl set libifxos.a library path
DEFAULT_IFXOS_LIBRARY_PATH='-L/missing/lib_ifxos/library/path'
AC_ARG_ENABLE(ifxos-library,
	AS_HELP_STRING([--enable-ifxos-library=-L/path/to/your/build/lib_ifxos/src] ,
						[Set the lib_ifxos library path. In this location the libifxos.a should be found]),
	[
	 if test -n "$enableval"; then
		 echo Set the libifxos.a library path to $enableval
		 AC_SUBST([IFXOS_LIBRARY_PATH],
					 [$enableval])
	 else
		 echo Set the lib_board_config library path $DEFAULT_IFXOS_LIBRARY_PATH
		 AC_SUBST([IFXOS_LIBRARY_PATH],
					 [$DEFAULT_IFXOS_LIBRARY_PATH])
	 fi
	],
	[
		echo Set the libifxos.a library path $DEFAULT_IFXOS_LIBRARY_PATH
		AC_SUBST([IFXOS_LIBRARY_PATH],
					[$DEFAULT_IFXOS_LIBRARY_PATH])
	]
)

dnl set lib_ifxos include path
DEFAULT_IFXOS_INCLUDE_PATH='-I/missing/lib_ifxos/include/path'
AC_ARG_ENABLE(ifxos-include,
	AC_HELP_STRING([--enable-ifxos-include=-I/path/to/your/lib_ifxos/src/include],
						[Set the lib_ifxos include path.]),
	[
	 if test -n "$enableval"; then
		 echo Set the lib_ifxos include path $enableval
		 AC_SUBST([IFXOS_INCLUDE_PATH],
					 [$enableval])
	 else
		 echo -e Set the default lib_ifxos include path $DEFAULT_IFXOS_INCLUDE_PATH
		 AC_SUBST([IFXOS_INCLUDE_PATH],
					 [$DEFAULT_IFXOS_INCLUDE_PATH])
	 fi
	],
	[
		echo -e Set the default lib_ifxos include path $DEFAULT_IFXOS_INCLUDE_PATH
		AC_SUBST([IFXOS_INCLUDE_PATH],
					[$DEFAULT_IFXOS_INCLUDE_PATH])
	]
)

dnl enable IFXOS System Object support
AC_ARG_ENABLE(ifxos-sys-obj-support,
	AS_HELP_STRING(
		[--enable-ifxos-sys-obj-support],[Support IFXOS System Objects.]
	),
	[
		if test "$enableval" = yes; then
			AM_CONDITIONAL(HAVE_IFXOS_SYSOBJ_SUPPORT, true)
			AC_SUBST([HAVE_IFXOS_SYSOBJ_SUPPORT],[yes])
		else
			AM_CONDITIONAL(HAVE_IFXOS_SYSOBJ_SUPPORT, false)
			AC_SUBST([HAVE_IFXOS_SYSOBJ_SUPPORT],[no])
		fi
	],
	[
		AM_CONDITIONAL(HAVE_IFXOS_SYSOBJ_SUPPORT, false)
		AC_SUBST([HAVE_IFXOS_SYSOBJ_SUPPORT],[no])
	]
)

packagebuilddir=.
packagesrcdir=`cd $srcdir && pwd`
currentdir=`pwd`

dnl Set the DTI Include Path for the default agent
# DTI_INCLUDE_PATH=-I$ac_pwd/src/include
DTI_INCLUDE_PATH=-I$packagesrcdir/src/include
AC_SUBST([DTI_INCLUDE_PATH],[$DTI_INCLUDE_PATH])

AC_SUBST([DTI_TARGET_OPTIONS],[$DTI_TARGET_OPTIONS])
AC_SUBST([DISTCHECK_CONFIGURE_PARAMS],[$CONFIGURE_OPTIONS])

echo \
"------------------------------------------------------------------------
Configuration:

	source code location:         ${srcdir}
	compiler:                     ${CC}
	compiler flags:               ${CFLAGS}
	host system type:             ${host}
	install path:                 ${prefix}
	project build:                ${currentdir} ${packagebuilddir}
	kernel include path:          ${KERNEL_INCL_PATH}
	kernel build path:            ${KERNEL_BUILD_PATH}
	kernel architecture:          ${KERNEL_ARCH}
	package source path:          ${packagesrcdir}
	DTI Client:                   ${BUILD_DTI_CLIENT}
	Device GENERIC:               ${DEVICE_GENERIC}
	Add CLI:                      ${INCLUDE_CLI_SUPPORT}
	Device Drv include path:      ${DEV_DRIVER_INCL_PATH}
	target library path:          ${TARGET_LIBRARY_PATH}
	target include path:          ${TARGET_INCLUDE_PATH}
	ifxos library path:           ${IFXOS_LIBRARY_PATH}
	ifxos include path:           ${IFXOS_INCLUDE_PATH}
	IFXOS Object Support:         ${HAVE_IFXOS_SYSOBJ_SUPPORT}

	target options:               ${DTI_TARGET_OPTIONS}

Settings:
	configure options:            ${CONFIGURE_OPTIONS}
------------------------------------------------------------------------"

AC_CONFIG_FILES([Makefile src/Makefile application/dti_agent/src/Makefile])
AC_OUTPUT


