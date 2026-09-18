| Vector | IRQ | Device | EOI |
|---|---|---|---|
| 0x20 | IRQ0 | PIT (system timer) | Master |
| 0x21 | IRQ1 | PS/2 keyboard | Master |
| 0x22 | IRQ2 | Cascade to slave PIC (never raised) | Master |
| 0x23 | IRQ3 | COM2 / COM4 | Master |
| 0x24 | IRQ4 | COM1 / COM3 | Master |
| 0x25 | IRQ5 | LPT2 / sound card | Master |
| 0x26 | IRQ6 | Floppy controller | Master |
| 0x27 | IRQ7 | LPT1 / spurious master IRQ | Master |
| 0x28 | IRQ8 | CMOS real-time clock | Slave + master |
| 0x29 | IRQ9 | Free / ACPI SCI (redirected IRQ2) | Slave + master |
| 0x2A | IRQ10 | Free (often NIC / USB) | Slave + master |
| 0x2B | IRQ11 | Free (often PCI) | Slave + master |
| 0x2C | IRQ12 | PS/2 mouse | Slave + master |
| 0x2D | IRQ13 | FPU / coprocessor | Slave + master |
| 0x2E | IRQ14 | Primary ATA | Slave + master |
| 0x2F | IRQ15 | Secondary ATA / spurious slave IRQ | Slave + master |