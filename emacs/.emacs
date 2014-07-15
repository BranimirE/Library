;/////////////  Cerrar } y poner enter si hay un ( atras ////////////
(defun autocierredellaves ()
	"Insert {}.
	Threat is as function body when from endline before )"
	(interactive)
	(if (looking-back "\\()\\|try\\|else\\|const\\|:\\)$")
	(progn
		(indent-according-to-mode)
		(insert " {\n\n}")
		(indent-according-to-mode)
		(forward-line -1)
		(indent-according-to-mode))
	(insert "{}")
	(backward-char)))
	(add-hook 'c-mode-common-hook 'my-c-common-hook)
	(defun my-c-common-hook ()
		(define-key c-mode-base-map "{" 'autocierredellaves))
;////////////////////////////////////////////////////////////////////

;//////////////////////// Auto cerrar llaves ////////////////////////
;;(electric-pair-mode t) ;;En emacs24 si no (:-|):
(defun electric-pair ()
	"If at end of line, insert character pair without surrounding spaces.
	Otherwise, just insert the typed character."
	(interactive)
	(if (eolp) (let (parens-require-spaces) (insert-pair)) 
		(self-insert-command 1)))

(add-hook 'c-mode-common-hook
	(lambda ()
		(define-key c-mode-base-map "\"" 'electric-pair)
		(define-key c-mode-base-map "\'" 'electric-pair)
		(define-key c-mode-base-map "(" 'electric-pair)
			(define-key c-mode-base-map "[" 'electric-pair)
			(define-key c-mode-base-map "{" 'electric-pair)))
;////////////////////////////////////////////////////////////////////

;/////// Autocompletar con shif + tab para saltar opciones //////////
;Por defecto es: "M-/"
(global-set-key (kbd "<backtab>") 'dabbrev-expand)
(define-key minibuffer-local-map (kbd "<backtab>") 'dabbrev-expand)
;////////////////////////////////////////////////////////////////////

;//////////////////  Resaltar pares de parentesis  //////////////////
(show-paren-mode t)
;////////////////////////////////////////////////////////////////////

;/////////////////  Autoidentar la linea siguiente  /////////////////
(add-hook 'c-mode-common-hook
	(lambda ()
		(define-key c-mode-base-map (kbd "RET") 'newline-and-indent)))
;////////////////////////////////////////////////////////////////////

;//////////////// Ocultar la barra de herramientas //////////////////
(tool-bar-mode 0)
;////////////////////////////////////////////////////////////////////

;///////////////////////// Ocultar el menu //////////////////////////
(menu-bar-mode 0)
;////////////////////////////////////////////////////////////////////

;///////////////// Mostrar el numero de las lineas  /////////////////
(global-linum-mode t) ;; mostrar
(setq linum-format "%d ") ;; arreglar error al aumentar de tamaño
;////////////////////////////////////////////////////////////////////

;///////////////// Mostrar el numero de las columns /////////////////
(column-number-mode t)
;////////////////////////////////////////////////////////////////////

;////////////// Fondo transparente :D (solo emacs24+)  //////////////
(set-frame-parameter (selected-frame) 'alpha '(96) )
;////////////////////////////////////////////////////////////////////

;////////////////////  Resaltar la linea actual  ////////////////////
(defface hl-line '((t (:background "Gray10")))		;;Cambiar
  "Face to use for `hl-line-face'." :group 'hl-line);;de
(setq hl-line-face 'hl-line)						;;color
(global-hl-line-mode t)								
;////////////////////////////////////////////////////////////////////

;/////////////////////  Cargar el tema molokai  /////////////////////
;solo si esta disponible "molokai-theme.el": copiarlo en ".emacs.d"
;(load-theme 'molokai)
;////////////////////////////////////////////////////////////////////

;/////////////////  Poner el fondo en color #121212 /////////////////
(set-background-color "#121212")
;////////////////////////////////////////////////////////////////////