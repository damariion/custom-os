| Vector | Exception |
|---|---|
| 0x00 | Divide error |
| 0x01 | Debug |
| 0x02 | NMI |
| 0x03 | Breakpoint (`int3`) |
| 0x04 | Overflow (`into`) |
| 0x05 | BOUND range exceeded |
| 0x06 | Invalid opcode |
| 0x07 | Device not available |
| 0x08 | Double fault |
| 0x09 | Coprocessor segment overrun |
| 0x0A | Invalid TSS |
| 0x0B | Segment not present |
| 0x0C | Stack-segment fault |
| 0x0D | General protection |
| 0x0E | Page fault |
| 0x0F | Reserved |
| 0x10 | x87 floating-point error |
| 0x11 | Alignment check |
| 0x12 | Machine check |
| 0x13 | SIMD floating-point |
| 0x14 | Virtualisation exception |
| 0x15 | Control protection (CET) |
| 0x16-0x1B | Reserved |
| 0x1C | Hypervisor injection (AMD) |
| 0x1D | VMM communication (AMD SEV-ES) |
| 0x1E | Security exception (AMD) |
| 0x1F | Reserved |
| 0x20-0xFF | User-defined (IRQs, syscalls) |