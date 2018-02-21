 
;TEXT SECTION
 
			section			.txt
 
			global			main
 
main:		nop									;main PROC
			push			rbp
			mov				rbp,rsp
			push			3						;emit numbers
			pop				qword [A]				;print assignments
			push			2						;emit numbers
			pop				qword [B]				;print assignments
			push			qword [A]				;print identifiers
			pop				rbx						;print addition ops
			pop				rax
			add				rax,rbx					;adds the contents of rax and rbx
			push			rax
			push			qword [B]				;print identifiers
			push			qword [A]				;print identifiers
			pop				qword [E]				;print assignments
