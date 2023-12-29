[Rainmeter]
ContextTitle="[msrRamContextString]"
ContextAction=[!WriteKeyValue Variables showFreeMem (abs(#showFreeMem#-1)) "#CURRENTPATH#shared.inc"][!Refresh #CURRENTCONFIG#]
ContextTitle2="[msrDiskContextString]"
ContextAction2=[!WriteKeyValue Variables showUsedDisk (abs(#showUsedDisk#-1)) "#CURRENTPATH#shared.inc"][!Refresh #CURRENTCONFIG#]
ContextTitle3="Edit hard drive letter"
ContextAction3=["#CURRENTPATH#shared.inc"]
ContextTitle4="Change Label color"
ContextAction4=["#CURRENTPATH#system-v.ini"]


;           _   _   _                  __   __
;  ___  ___| |_| |_(_)_ __   __ _ ___  \ \  \ \
; / __|/ _ \ __| __| | '_ \ / _` / __|  \ \  \ \
; \__ \  __/ |_| |_| | | | | (_| \__ \  / /  / /
; |___/\___|\__|\__|_|_| |_|\__, |___/ /_/  /_/
;                           |___/

[Variables]
; Set your hard drive letter here, e.g. "drive=C:", "drive="F:", etc.
drive1=C:
drive2=D:
drive3=E:
drive4=F:
; (#PROGRAMDRIVE# is the drive where Rainmeter is installed)
drive=#PROGRAMDRIVE#


; Set to '1' to show free RAM, or '0' to show used RAM
showFreeMem=0

; Set to '1' to show used disk space, or '0' to show free disk space
showUsedDisk=0

;   __   __           _   _   _
;  / /  / /  ___  ___| |_| |_(_)_ __   __ _ ___
; / /  / /  / __|/ _ \ __| __| | '_ \ / _` / __|
; \ \  \ \  \__ \  __/ |_| |_| | | | | (_| \__ \
;  \_\  \_\ |___/\___|\__|\__|_|_| |_|\__, |___/
;                                     |___/

[msrRamContextString]
Measure=Calc
Formula=#showFreeMem#
Substitute="0":"Switch to free RAM","1":"Switch to used RAM"

[msrDiskContextString]
Measure=Calc
Formula=#showUsedDisk#
Substitute="0":"Switch to used disk","1":"Switch to free disk"

[MeasureCPUUsage]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\HWiNFO64\VSB
RegValue=Value2
MinValue=0
MaxValue=100

[MeasureCPUTemp]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\HWiNFO64\VSB
RegValue=Value3

[MeasureCPUFreq]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\HWiNFO64\VSB
RegValue=Value1

[msrCPU]
Measure=CPU
Processor=0

;==================================================================

[MeasureGPUUsage]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\HWiNFO64\VSB
RegValue=Value10
MinValue=0
MaxValue=100

[MeasureGPUUsageRaw]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\HWiNFO64\VSB
RegValue=ValueRaw10
MinValue=0
MaxValue=100

[MeasureGPUTemp]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\HWiNFO64\VSB
RegValue=Value5

[MeasureGPUFreq]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\HWiNFO64\VSB
RegValue=Value8

;==================================================================

[MeasureNetUp]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\HWiNFO64\VSB
RegValue=Value12

[MeasureNetDown]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\HWiNFO64\VSB
RegValue=Value11

;==================================================================

[MeasureUsedMemory]
Measure=PhysicalMemory

;==================================================================

[MeasureTotalDiskSpace1]
Measure=FreeDiskSpace
Drive=C:
Total=1
UpdateDivider=5

[MeasureFreeDiskSpace1]
Measure=FreeDiskSpace
Drive=C:
UpdateDivider=5
MinValue=0
MaxValue=[MeasureTotalDiskSpace]

[MeasureUsedDiskSpace1]
Measure=FreeDiskSpace
Drive=#drive1#
InvertMeasure=1
UpdateDivider=5

[MeasureUsedDiskSpace2]
Measure=FreeDiskSpace
Drive=#drive2#
InvertMeasure=1
UpdateDivider=5

[MeasureUsedDiskSpace3]
Measure=FreeDiskSpace
Drive=#drive3#
InvertMeasure=1
UpdateDivider=5

[MeasureUsedDiskSpace4]
Measure=FreeDiskSpace
Drive=#drive4#
InvertMeasure=1
UpdateDivider=5

;==================================================================


[msrCPUTemp]
Measure=Plugin
Plugin=CoreTemp
CoreTempType=Temperature

[msrCPUSpeed]
Measure=Plugin
Plugin=CoreTemp
CoreTempType=CpuSpeed

[msrGPU]
Measure=Plugin
Plugin=UsageMonitor
Alias=GPU
Index=0

[msrMem]
Measure=PhysicalMemory
InvertMeasure=#showFreeMem#
UpdateDivider=3

[msrDrive1]
Measure=FreeDiskSpace
Drive=#drive1#
InvertMeasure=#showUsedDisk#
UpdateDivider=10

[msrDrive2]
Measure=FreeDiskSpace
Drive=#drive2#
InvertMeasure=#showUsedDisk#
UpdateDivider=10

[msrDrive3]
Measure=FreeDiskSpace
Drive=#drive3#
InvertMeasure=#showUsedDisk#
UpdateDivider=10

[msrDrive4]
Measure=FreeDiskSpace
Drive=#drive4#
InvertMeasure=#showUsedDisk#
UpdateDivider=10

[msrNetUp]
Measure=NetOut
Interface=0
NetOutSpeed=0

[msrNetDown]
Measure=NetIn
Interface=0
NetInSpeed=0
