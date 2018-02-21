 
;TEXT SECTION
 
			section		.txt
 
			global		main
 
main:		nop									;main PROC
			push		rbp
			mov			rbp,rsp
			push		3						;emit numbers
			push		2						;emit numbers
			pop			qword [A]				;print lines
			pop			qword [B]				;print lines
			pop			qword [A]				;print lines
