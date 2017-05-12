COPY     StArT   0x1000
FIRST    STL     RETADR
CLOOP    JSUB    RDREC
         LDA     LENGTH
         COMP    ZERO
         JEQ     ENDFIL
         JSuB    WRREC
         J       CLOOP
ENDFIL   LDA     EOF
         STA     BUFFER
         LDA     THREE
         sta     LENGTH
         JSuB    WRREC
         LDL     RETADR
         RSUB
EOF      BYTE    C'EOF'
THREE    WORD    1,2,3
ZERO     WORD    0
RETADR   RESW    1
LENGTH   RESW    1
BUFFER   RESB    4096
RDREC    LDx     ZERO
         LDA     ZERO
RLOOP    TD      INPUT
         JEQ     RLOOP
         RD      INPUT
         COMP    ZERO
         JEQ     EXIT
         STCH    BUFFER,X
         TIX     MAXLEN
         JLT     RLOOP
EXIT     STX     LENGTH
         RSUB
INPUT    BYTE    X'F1'
MAXLEN   WORD    4096
WRREC    LDX     ZERO
WLOOP    TD      OUTPUT
         JEQ     WLOOP
         LDCH    BUFFER,X
         WD      OUTPUT
         TIX     LENGTH
         JLT     WLOOP
         RSUB
OUTPUT   BYTE    X'05'
         END     COPY