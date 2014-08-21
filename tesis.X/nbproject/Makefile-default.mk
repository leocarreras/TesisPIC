#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/tesis.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/tesis.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=pwmconfig.c globaldefinitions.c qeiconfig.c tesismain.c timerconfig.c uartconfig.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/pwmconfig.o ${OBJECTDIR}/globaldefinitions.o ${OBJECTDIR}/qeiconfig.o ${OBJECTDIR}/tesismain.o ${OBJECTDIR}/timerconfig.o ${OBJECTDIR}/uartconfig.o
POSSIBLE_DEPFILES=${OBJECTDIR}/pwmconfig.o.d ${OBJECTDIR}/globaldefinitions.o.d ${OBJECTDIR}/qeiconfig.o.d ${OBJECTDIR}/tesismain.o.d ${OBJECTDIR}/timerconfig.o.d ${OBJECTDIR}/uartconfig.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/pwmconfig.o ${OBJECTDIR}/globaldefinitions.o ${OBJECTDIR}/qeiconfig.o ${OBJECTDIR}/tesismain.o ${OBJECTDIR}/timerconfig.o ${OBJECTDIR}/uartconfig.o

# Source Files
SOURCEFILES=pwmconfig.c globaldefinitions.c qeiconfig.c tesismain.c timerconfig.c uartconfig.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/tesis.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ64MC802
MP_LINKER_FILE_OPTION=,-Tp33FJ64MC802.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/pwmconfig.o: pwmconfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/pwmconfig.o.d 
	@${RM} ${OBJECTDIR}/pwmconfig.o.ok ${OBJECTDIR}/pwmconfig.o.err 
	@${RM} ${OBJECTDIR}/pwmconfig.o 
	@${FIXDEPS} "${OBJECTDIR}/pwmconfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/pwmconfig.o.d" -o ${OBJECTDIR}/pwmconfig.o pwmconfig.c    
	
${OBJECTDIR}/globaldefinitions.o: globaldefinitions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/globaldefinitions.o.d 
	@${RM} ${OBJECTDIR}/globaldefinitions.o.ok ${OBJECTDIR}/globaldefinitions.o.err 
	@${RM} ${OBJECTDIR}/globaldefinitions.o 
	@${FIXDEPS} "${OBJECTDIR}/globaldefinitions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/globaldefinitions.o.d" -o ${OBJECTDIR}/globaldefinitions.o globaldefinitions.c    
	
${OBJECTDIR}/qeiconfig.o: qeiconfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/qeiconfig.o.d 
	@${RM} ${OBJECTDIR}/qeiconfig.o.ok ${OBJECTDIR}/qeiconfig.o.err 
	@${RM} ${OBJECTDIR}/qeiconfig.o 
	@${FIXDEPS} "${OBJECTDIR}/qeiconfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/qeiconfig.o.d" -o ${OBJECTDIR}/qeiconfig.o qeiconfig.c    
	
${OBJECTDIR}/tesismain.o: tesismain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/tesismain.o.d 
	@${RM} ${OBJECTDIR}/tesismain.o.ok ${OBJECTDIR}/tesismain.o.err 
	@${RM} ${OBJECTDIR}/tesismain.o 
	@${FIXDEPS} "${OBJECTDIR}/tesismain.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/tesismain.o.d" -o ${OBJECTDIR}/tesismain.o tesismain.c    
	
${OBJECTDIR}/timerconfig.o: timerconfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/timerconfig.o.d 
	@${RM} ${OBJECTDIR}/timerconfig.o.ok ${OBJECTDIR}/timerconfig.o.err 
	@${RM} ${OBJECTDIR}/timerconfig.o 
	@${FIXDEPS} "${OBJECTDIR}/timerconfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/timerconfig.o.d" -o ${OBJECTDIR}/timerconfig.o timerconfig.c    
	
${OBJECTDIR}/uartconfig.o: uartconfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/uartconfig.o.d 
	@${RM} ${OBJECTDIR}/uartconfig.o.ok ${OBJECTDIR}/uartconfig.o.err 
	@${RM} ${OBJECTDIR}/uartconfig.o 
	@${FIXDEPS} "${OBJECTDIR}/uartconfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/uartconfig.o.d" -o ${OBJECTDIR}/uartconfig.o uartconfig.c    
	
else
${OBJECTDIR}/pwmconfig.o: pwmconfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/pwmconfig.o.d 
	@${RM} ${OBJECTDIR}/pwmconfig.o.ok ${OBJECTDIR}/pwmconfig.o.err 
	@${RM} ${OBJECTDIR}/pwmconfig.o 
	@${FIXDEPS} "${OBJECTDIR}/pwmconfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/pwmconfig.o.d" -o ${OBJECTDIR}/pwmconfig.o pwmconfig.c    
	
${OBJECTDIR}/globaldefinitions.o: globaldefinitions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/globaldefinitions.o.d 
	@${RM} ${OBJECTDIR}/globaldefinitions.o.ok ${OBJECTDIR}/globaldefinitions.o.err 
	@${RM} ${OBJECTDIR}/globaldefinitions.o 
	@${FIXDEPS} "${OBJECTDIR}/globaldefinitions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/globaldefinitions.o.d" -o ${OBJECTDIR}/globaldefinitions.o globaldefinitions.c    
	
${OBJECTDIR}/qeiconfig.o: qeiconfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/qeiconfig.o.d 
	@${RM} ${OBJECTDIR}/qeiconfig.o.ok ${OBJECTDIR}/qeiconfig.o.err 
	@${RM} ${OBJECTDIR}/qeiconfig.o 
	@${FIXDEPS} "${OBJECTDIR}/qeiconfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/qeiconfig.o.d" -o ${OBJECTDIR}/qeiconfig.o qeiconfig.c    
	
${OBJECTDIR}/tesismain.o: tesismain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/tesismain.o.d 
	@${RM} ${OBJECTDIR}/tesismain.o.ok ${OBJECTDIR}/tesismain.o.err 
	@${RM} ${OBJECTDIR}/tesismain.o 
	@${FIXDEPS} "${OBJECTDIR}/tesismain.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/tesismain.o.d" -o ${OBJECTDIR}/tesismain.o tesismain.c    
	
${OBJECTDIR}/timerconfig.o: timerconfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/timerconfig.o.d 
	@${RM} ${OBJECTDIR}/timerconfig.o.ok ${OBJECTDIR}/timerconfig.o.err 
	@${RM} ${OBJECTDIR}/timerconfig.o 
	@${FIXDEPS} "${OBJECTDIR}/timerconfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/timerconfig.o.d" -o ${OBJECTDIR}/timerconfig.o timerconfig.c    
	
${OBJECTDIR}/uartconfig.o: uartconfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/uartconfig.o.d 
	@${RM} ${OBJECTDIR}/uartconfig.o.ok ${OBJECTDIR}/uartconfig.o.err 
	@${RM} ${OBJECTDIR}/uartconfig.o 
	@${FIXDEPS} "${OBJECTDIR}/uartconfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/uartconfig.o.d" -o ${OBJECTDIR}/uartconfig.o uartconfig.c    
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/tesis.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG  -o dist/${CND_CONF}/${IMAGE_TYPE}/tesis.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -Wl,--defsym=__MPLAB_BUILD=1,--stack=16,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1
else
dist/${CND_CONF}/${IMAGE_TYPE}/tesis.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/tesis.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -Wl,--defsym=__MPLAB_BUILD=1,--stack=16,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION)
	${MP_CC_DIR}\\pic30-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/tesis.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -omf=elf
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
