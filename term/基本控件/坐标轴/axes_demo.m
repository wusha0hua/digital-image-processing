function varargout = axes_demo(varargin)
% AXES_DEMO MATLAB code for axes_demo.fig
%      AXES_DEMO, by itself, creates a new AXES_DEMO or raises the existing
%      singleton*.
%
%      H = AXES_DEMO returns the handle to a new AXES_DEMO or the handle to
%      the existing singleton*.
%
%      AXES_DEMO('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in AXES_DEMO.M with the given input arguments.
%
%      AXES_DEMO('Property','Value',...) creates a new AXES_DEMO or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before axes_demo_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to axes_demo_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help axes_demo

% Last Modified by GUIDE v2.5 07-Nov-2015 17:11:14

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @axes_demo_OpeningFcn, ...
                   'gui_OutputFcn',  @axes_demo_OutputFcn, ...
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


% --- Executes just before axes_demo is made visible.
function axes_demo_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to axes_demo (see VARARGIN)

% Choose default command line output for axes_demo
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes axes_demo wait for user response (see UIRESUME)
% uiwait(handles.figure_main);


% --- Outputs from this function are returned to the command line.
function varargout = axes_demo_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in image_load.
function image_load_Callback(hObject, eventdata, handles)
% hObject    handle to image_load (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
[FileName, PathName, FilterIndex] = uigetfile('*.tif', 'ÔØÈëÍ¼ÏñÎÄ¼þ'); 
if FilterIndex
    image = imread(fullfile(PathName, FileName));
end
imshow(image, 'Parent', handles.axes_image);
