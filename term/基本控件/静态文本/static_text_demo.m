function varargout = static_text_demo(varargin)
% STATIC_TEXT_DEMO MATLAB code for static_text_demo.fig
%      STATIC_TEXT_DEMO, by itself, creates a new STATIC_TEXT_DEMO or raises the existing
%      singleton*.
%
%      H = STATIC_TEXT_DEMO returns the handle to a new STATIC_TEXT_DEMO or the handle to
%      the existing singleton*.
%
%      STATIC_TEXT_DEMO('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in STATIC_TEXT_DEMO.M with the given input arguments.
%
%      STATIC_TEXT_DEMO('Property','Value',...) creates a new STATIC_TEXT_DEMO or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before static_text_demo_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to static_text_demo_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help static_text_demo

% Last Modified by GUIDE v2.5 06-Nov-2015 16:00:55

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @static_text_demo_OpeningFcn, ...
                   'gui_OutputFcn',  @static_text_demo_OutputFcn, ...
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


% --- Executes just before static_text_demo is made visible.
function static_text_demo_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to static_text_demo (see VARARGIN)

% Choose default command line output for static_text_demo
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes static_text_demo wait for user response (see UIRESUME)
% uiwait(handles.figure_main);


% --- Outputs from this function are returned to the command line.
function varargout = static_text_demo_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in my_pushbutton.
function my_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to my_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
time_string = datestr(now, 'yyyy-mm-dd-HH:MM:SS');
set(handles.my_static_text, 'String', time_string, 'BackgroundColor', 'k', ...
    'ForegroundColor', 'y', 'HorizontalAlignment', 'left', 'FontSize', 20);
