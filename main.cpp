EXTERN UnityPluginLoad_ptr : QWORD
.CODE
UnityPluginLoad PROC
    jmp QWORD PTR [UnityPluginLoad_ptr]
UnityPluginLoad ENDP
END
