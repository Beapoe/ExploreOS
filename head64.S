.text
.code64
    mov $0x3f8,%dx
    mov $'A',%al
    out %al,%dx
    hlt