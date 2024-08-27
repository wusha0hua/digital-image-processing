function varargout = pushbutton_demo(varargin)
% PUSHBUTTON_DEMO MATLAB code for pushbutton_demo.fig
%      PUSHBUTTON_DEMO, by itself, creates a new PUSHBUTTON_DEMO or raises the existing
%      singleton*.
%
%      H = PUSHBUTTON_DEMO returns the handle to a new PUSHBUTTON_DEMO or the handle to
%      the existing singleton*.
%
%      PUSHBUTTON_DEMO('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in PUSHBUTTON_DEMO.M with the given input arguments.
%
%      PUSHBUTTON_DEMO('Property','Value',...) creates a new PUSHBUTTON_DEMO or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before pushbutton_demo_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to pushbutton_demo_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help pushbutton_demo

% Last Modified by GUIDE v2.5 06-Nov-2015 15:17:54

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @pushbutton_demo_OpeningFcn, ...
                   'gui_OutputFcn',  @pushbutton_demo_OutputFcn, ...
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


% --- Executes just before pushbutton_demo is made visible.
function pushbutton_demo_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to pushbutton_demo (see VARARGIN)

% Choose default command line output for pushbutton_demo
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes pushbutton_demo wait for user response (see UIRESUME)
% uiwait(handles.figure_main);


% --- Outputs from this function are returned to the command line.
function varargout = pushbutton_demo_OutputFcn(hObject, eventdata, handles) 
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
[FileName, PathName, FilterIndex] = uigetfile('*.png', 'µ¼Èë±³¾°Í¼Ïñ');
button_position = get(hObject, 'Position');
image = imresize(imread(fullfile(PathName, FileName)), [button_position(4), ...
    button_position(3)], 'bicubic');
set(hObject, 'CData', image);
