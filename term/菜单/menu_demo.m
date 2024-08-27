function varargout = menu_demo(varargin)
% MENU_DEMO MATLAB code for menu_demo.fig
%      MENU_DEMO, by itself, creates a new MENU_DEMO or raises the existing
%      singleton*.
%
%      H = MENU_DEMO returns the handle to a new MENU_DEMO or the handle to
%      the existing singleton*.
%
%      MENU_DEMO('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in MENU_DEMO.M with the given input arguments.
%
%      MENU_DEMO('Property','Value',...) creates a new MENU_DEMO or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before menu_demo_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to menu_demo_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help menu_demo

% Last Modified by GUIDE v2.5 09-Nov-2015 14:57:33

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @menu_demo_OpeningFcn, ...
                   'gui_OutputFcn',  @menu_demo_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before menu_demo is made visible.
function menu_demo_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to menu_demo (see VARARGIN)

% Choose default command line output for menu_demo
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes menu_demo wait for user response (see UIRESUME)
% uiwait(handles.figure_main);


% --- Outputs from this function are returned to the command line.
function varargout = menu_demo_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



function filter_frequency_domain_Callback(hObject, eventdata, handles)
% hObject    handle to filter_frequency_domain (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


function ideal_LBP_Callback(hObject, eventdata, handles)
% hObject    handle to ideal_LBP (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

function gaussian_LPF_Callback(hObject, eventdata, handles)
% hObject    handle to gaussian_LPF (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

function ideal_HPF_Callback(hObject, eventdata, handles)
% hObject    handle to ideal_HPF (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


function gaussian_HPF_Callback(hObject, eventdata, handles)
% hObject    handle to gaussian_HPF (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
