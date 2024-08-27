function varargout = gui_demo(varargin)
% GUI_DEMO MATLAB code for gui_demo.fig
%      GUI_DEMO, by itself, creates a new GUI_DEMO or raises the existing
%      singleton*.
%
%      H = GUI_DEMO returns the handle to a new GUI_DEMO or the handle to
%      the existing singleton*.
%
%      GUI_DEMO('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GUI_DEMO.M with the given input arguments.
%
%      GUI_DEMO('Property','Value',...) creates a new GUI_DEMO or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before gui_demo_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to gui_demo_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help gui_demo

% Last Modified by GUIDE v2.5 09-Nov-2015 10:37:48

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @gui_demo_OpeningFcn, ...
                   'gui_OutputFcn',  @gui_demo_OutputFcn, ...
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


% --- Executes just before gui_demo is made visible.
function gui_demo_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to gui_demo (see VARARGIN)

% Choose default command line output for gui_demo
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes gui_demo wait for user response (see UIRESUME)
% uiwait(handles.figure_main);


% --- Outputs from this function are returned to the command line.
function varargout = gui_demo_OutputFcn(hObject, eventdata, handles) 
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


% --- Executes on button press in my_checkbox.
function my_checkbox_Callback(hObject, eventdata, handles)
% hObject    handle to my_checkbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of my_checkbox
value = get(hObject, 'Value');


% --- Executes on slider movement.
function my_slider_Callback(hObject, eventdata, handles)
% hObject    handle to my_slider (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of slider


% --- Executes during object creation, after setting all properties.
function my_slider_CreateFcn(hObject, eventdata, handles)
% hObject    handle to my_slider (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end
