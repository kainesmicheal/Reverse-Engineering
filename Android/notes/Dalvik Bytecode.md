the machine mode and calling conventions are meant to approximately imitate common real architectures and C-style calling conventions

the machine is register based, and frames are fixed in size upon creation.

each frame consist of a particular number of registers (specified by the method) as well as any adjuct data needed to execute the method, such as (but not limited to) the program counter and a reference to the .dex file that contains the method.

when used for bit values (such as integers and floating point numbers), registers are considered 32bits wide. adjacent register pairs are used for 64-bit values. there is no aligment requirement for register pairs.

when used for object references, registers are considered wide enough to hold exactly one such reference.

(Object) null == (int) 0

the N arguments to a method land in the last N registers of the method's invocation frame, in order. wide arguments consume two registers, instance methods are passed a this reference as their first argument.

in practive it is uncommon for a method to need more than 16 registers, and because needing more than eight registers is reasonble common, many instructions are limited to only addressing the first 16 registers.

there are several pseudo-instructions that are used to hold variable length data payloads, which is referred to by regular instructions. the instuctions must be located in a even number bytecode offsets (4byte aligned). in order to meet this requirement, dex generation tools emit an extro nop insturction as a spacer if such an instruction would otherwise be unaligned. though not required, it is expected that most tools will choose to emit these instructions at the ends of methods. otherwise it would likely to cause that additional instructions would be needed to brach around them.

Synatx and mnemonics:

-> Dest then source ordering for arguments
-> some opcodes are suffixed with type
	32bit : unmarked
	64bit : -wide
	then, straightforward abbrevations, -boolean, -byte, -char, -short, -int, -long, -float, -object, -string, -class, -void.
	
move-wide/from16 vAA, vBBBB

move - base opcode
wide - suffix for 64 bit
from16 - referring source is a 16bit register
vAA - destination register range (v0 - v255)
vBBBB - source register range (v0 - v65535)

