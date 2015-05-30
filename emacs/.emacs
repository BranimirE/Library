(add-hook 'c-mode-common-hook
 (lambda ()
  (font-lock-add-keywords nil
   '(("\\<\\(DBG\\|forn\\|sz\\|all\\)\\>" . font-lock-keyword-face)
     ))))
      
;;(setq-default c-basic-offset 4) ;;cambiar identacion a 4 espacios
(setq-default indent-tabs-mode nil) ;; espacios en vez de tabs, arreglar identacion


;; auto completar llave de cierre y poner enter y posicionar el cursor
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

(show-paren-mode t);;//Mostrar pares de parentesis

(add-hook 'c-mode-common-hook;;Auto identar al poner enter
	  (lambda ()
	    (define-key c-mode-base-map (kbd "RET") 'newline-and-indent)))


(global-linum-mode t) ;; mostrar numero de las lineas
(setq linum-format "%d ") ;; arreglar error al aumentar de tamaño

(set-frame-parameter (selected-frame) 'alpha '(96) );fondo transparente (OPCIONAL)

(defface hl-line '((t (:background "Gray10")))      ;;Cambiar de
  "Face to use for `hl-line-face'." :group 'hl-line);;color de
(setq hl-line-face 'hl-line)                        ;;resaltado

(global-hl-line-mode t) ;; Resaltar la linea actual

(load-theme 'molokai);//Cargar tema molokai(si se cuenta con el archivo molokai.el)

;;Insertar plantilla con el comando "plantilla"
(defun plantilla ();//Insertar plantilla normal
  (interactive);;//Convertir en comando
  (insert-file-contents "~/template.cpp") ;;//path del archivo
  (forward-line 15) ;; insertar e ir a la linea 15
  (indent-according-to-mode);; insertar e identar
  )

(defun usaco ();//Insertar plantilla de usaco
  (interactive)
  (insert-file-contents "~/templateusaco.cpp")
  (forward-line 12)
  (indent-according-to-mode)
  )

(global-set-key (kbd "<backtab>") 'dabbrev-expand);Auto copletar
(define-key minibuffer-local-map (kbd "<backtab>") 'dabbrev-expand);necesario


(defun dividirBuffer()
  (interactive)
  (delete-other-windows)
  (split-window-horizontally)
  (switch-to-buffer-other-window "entrada")
;;  (insert-file-contents "entrada");;si es que existe
  (split-window-vertically)
  (switch-to-buffer-other-window "salida")
  (switch-to-buffer-other-window "entrada")
  (set-window-dedicated-p (selected-window) t)
  (switch-to-buffer-other-window "salida")
  (set-window-dedicated-p (selected-window) t)
  (other-window 1)
)
(global-set-key [f6] 'dividirBuffer) 

(defun compilar()
  (interactive)
  (setq archivo (file-name-nondirectory(buffer-file-name)))
  (save-buffer)
  (setq compilador "g++ -std=c++11")
  (compile (format "%s %s" compilador archivo))
)
(global-set-key [f9] 'compilar)

(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(custom-safe-themes (quote ("9fd20670758db15cc4d0b4442a74543888d2e445646b25f2755c65dcd6f1504b" default))))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )
