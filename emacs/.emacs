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

;;(electric-pair-mode t);;/Auto cierre de parentesis y corechetes

(show-paren-mode t);Mostar pares de parentesis

(add-hook 'c-mode-common-hook;Auto identar al poner enter
	(lambda ()
		(define-key c-mode-base-map (kbd "RET") 'newline-and-indent)))

(global-linum-mode t) ;; mostrar numero de lineas
(setq linum-format "%d ") ;; arreglar error al aumentar de tamaño

(set-frame-parameter (selected-frame) 'alpha '(96) );fondo transparente (opcional)

(defface hl-line '((t (:background "Gray10")))      ;;Cambiar de
  "Face to use for `hl-line-face'." :group 'hl-line);;color de
(setq hl-line-face 'hl-line)                        ;;resaltado
(global-hl-line-mode t) ; Resaltar la linea actual

(load-theme 'molokai);//Cargar tema molokai

(defun plantilla ();//Insertar plantilla
  (interactive)
  (insert-file-contents "~/template.cpp")
  (forward-line 12)
  (indent-according-to-mode)
)

(global-set-key (kbd "<backtab>") 'dabbrev-expand);Auto copletar
(define-key minibuffer-local-map (kbd "<backtab>") 'dabbrev-expand);necesario