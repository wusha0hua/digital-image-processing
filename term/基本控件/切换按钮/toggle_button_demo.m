function varargout = toggle_button_demo(varargin)
% TOGGLE_BUTTON_DEMO MATLAB code for toggle_button_demo.fig
%      TOGGLE_BUTTON_DEMO, by itself, creates a new TOGGLE_BUTTON_DEMO or raises the existing
%      singleton*.
%
%      H = TOGGLE_BUTTON_DEMO returns the handle to a new TOGGLE_BUTTON_DEMO or the handle to
%      the existing singleton*.
%
%      TOGGLE_BUTTON_DEMO('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in TOGGLE_BUTTON_DEMO.M with the given input arguments.
%
%      TOGGLE_BUTTON_DEMO('Property','Value',...) creates a new TOGGLE_BUTTON_DEMO or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before toggle_button_demo_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to toggle_button_demo_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help toggle_button_demo

% Last Modified by GUIDE v2.5 06-Nov-2015 17:01:56

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @toggle_button_demo_OpeningFcn, ...
                   'gui_OutputFcn',  @toggle_button_demo_OutputFcn, ...
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


% --- Executes just before toggle_button_demo is made visible.
function toggle_button_demo_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to toggle_button_demo (see VARARGIN)

% Choose default command line output for toggle_button_demo
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes toggle_button_demo wait for user response (see UIRESUME)
% uiwait(handles.figure_main);


% --- Outputs from this function are returned to the command line.
function varargout = toggle_button_demo_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in my_togglebutton.
function my_togglebutton_Callback(hObject, eventdata, handles)
% hObject    handle to my_togglebutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of my_togglebutton
value = get(hObject,'Value');
if value
    set(handles.my_static_text, 'ForegroundColor', 'r', 'String', 'Toggle Button被按下');
else
    set(handles.my_static_text, 'ForegroundColor', 'k', 'String', 'Toggle Buttonc处于弹起状态');
end
