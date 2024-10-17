" Enable syntax highlighting
syntax on

" Set line numbers
set number

" Enable mouse support
set mouse=a

" Set the default indentation
set tabstop=4       " Number of spaces a <Tab> counts for
set shiftwidth=4    " Number of spaces to use for each step of (auto)indent
set noexpandtab       " Use spaces instead of tabs

" Enable line wrapping
set wrap

" Configure the colorscheme
colorscheme habamax " Change this to your desired colorscheme

" Enable file type detection
filetype plugin indent on

call plug#begin('~/.vim/plugged')

" Add plugins here
Plug 'morhetz/gruvbox'               " Gruvbox colorscheme
Plug 'tpope/vim-sensible'            " A sensible Vim configuration
Plug 'nvim-treesitter/nvim-treesitter', {'do': ':TSUpdate'} " Syntax highlighting

call plug#end()

" Set the font for GUI
 if has("gui_running")
    set guifont=FiraMono\ Nerd\ Font:h12
endif

